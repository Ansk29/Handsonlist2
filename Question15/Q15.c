
/*
============================================================================
Name : 15.c
Author : Anshul Kakirde
Description: Write a simple program to send some data from parent to the child process.
Date: , 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char message[] = "Hello from parent!";
    char buffer[100];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        close(pipefd[1]);
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(pipefd[0]);
    } else {
        close(pipefd[0]);
        write(pipefd[1], message, strlen(message) + 1);
        close(pipefd[1]);
    }

    return 0;
}

