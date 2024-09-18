#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipefd[2];  // pipefd[0]: read end, pipefd[1]: write end
    pid_t pid;

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {  // Child process (ls -l)
        close(pipefd[0]);  // Close read end
        dup(pipefd[1]);    // Duplicate write end to stdout (fd 1)
        close(pipefd[1]);  // Close original write end
        execlp("ls", "ls", "-l", NULL);  // Execute "ls -l"
        perror("execlp");
        exit(EXIT_FAILURE);
    } else {  // Parent process (wc)
        close(pipefd[1]);  // Close write end
        dup(pipefd[0]);    // Duplicate read end to stdin (fd 0)
        close(pipefd[0]);  // Close original read end
        execlp("wc", "wc", NULL);  // Execute "wc"
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    return 0;
}

