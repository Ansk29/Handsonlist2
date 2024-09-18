/*
============================================================================
Name : 23.c
Author : Anshul Kakirde
Description: Write a program to print the maximum number of files can be opened within a process and size of a pipe (circular buffer).
Date: , 2024.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    long max_files = sysconf(_SC_OPEN_MAX);
    printf("Max number of open files: %ld\n", max_files);

    int pipefd[2];
    pipe(pipefd);
    int pipe_size = fpathconf(pipefd[0], _PC_PIPE_BUF);
    printf("Pipe size: %d bytes\n", pipe_size);

    close(pipefd[0]);
    close(pipefd[1]);

    return 0;
}


/*Max number of open files: 1024
Pipe size: 4096 bytes*/
