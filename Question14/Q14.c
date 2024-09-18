
/*
============================================================================
Name : 14.c
Author : Anshul Kakirde
Description: Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monito
Date: , 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2]; // Array to hold file descriptors for the pipe
    char message[] = "Hello, pipe!";
    char buffer[100];

    // Create the pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Write to the pipe
    write(pipefd[1], message, strlen(message) + 1);

    // Read from the pipe
    read(pipefd[0], buffer, sizeof(buffer));

    // Display the message
    printf("Read from pipe: %s\n", buffer);

    return 0;
}

