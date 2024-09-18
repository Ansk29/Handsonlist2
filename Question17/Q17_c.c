#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int pipefd[2];
    pid_t pid1, pid2;

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid1 = fork();
    if (pid1 < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0) { // First child
        close(pipefd[0]);
        fcntl(pipefd[1], F_DUPFD, STDOUT_FILENO);
        close(pipefd[1]);
        execlp("ls", "ls", "-l", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    } else {
        pid2 = fork();
        if (pid2 < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid2 == 0) { // Second child
            close(pipefd[1]);
            fcntl(pipefd[0], F_DUPFD, STDIN_FILENO);
            close(pipefd[0]);
            execlp("wc", "wc", NULL);
            perror("execlp");
            exit(EXIT_FAILURE);
        } else {
            close(pipefd[0]);
            close(pipefd[1]);
            wait(NULL);
            wait(NULL);
        }
    }

    return 0;
}

