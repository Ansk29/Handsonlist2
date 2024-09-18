/*
============================================================================
Name : 13.c
Author : Anshul Kakirde
Description :Write two programs: first program is waiting to catch SIGSTOP signal, the second program will send the signal (using kill system call). Find out whether the first program is able to catch the signal or not.
Date: , 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2]; 
    char message[] = "Writing in the pipe";
    char buffer[100];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }


    write(pipefd[1], message, strlen(message) + 1);


    read(pipefd[0], buffer, sizeof(buffer));


    printf("Reading from the pipe%s\n", buffer);

    return 0;
}


/*Reading from the pipe Writing in the pipe*/

