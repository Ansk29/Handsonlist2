
/*
============================================================================
Name : 18.c
Author : Anshul Kakirde
Description: . Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
Date: , 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipefd1[2];
    int pipefd2[2];
    pid_t pid;

    if (pipe(pipefd1) == -1 || pipe(pipefd2) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == 0) {
        close(pipefd1[0]);
        close(pipefd2[0]);
        close(pipefd2[1]);
        dup2(pipefd1[1], STDOUT_FILENO);
        close(pipefd1[1]);
        execlp("ls", "ls", "-l", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    } else {
        pid = fork();
        if (pid == 0) {
            close(pipefd1[1]);
            close(pipefd2[1]);
            dup2(pipefd1[0], STDIN_FILENO);
            dup2(pipefd2[0], STDOUT_FILENO);
            close(pipefd1[0]);
            close(pipefd2[0]);
            execlp("grep", "grep", "^d", NULL);
            perror("execlp");
            exit(EXIT_FAILURE);
        } else {
            close(pipefd1[0]);
            close(pipefd1[1]);
            close(pipefd2[0]);
            close(pipefd2[1]);
            execlp("wc", "wc", "-l", NULL);
            perror("execlp");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

