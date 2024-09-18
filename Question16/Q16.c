
/*
============================================================================
Name : 16.c
Author : Anshul Kakirde
Description: Write a program to send and receive data from parent to child vice versa. Use two way communication.
Date: , 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd1[2];   //pipe one banaya jiske do end he 
    int pipefd2[2];   // pipe 2 banaya jiske do end he ;
    pid_t pid;
    char parent_message[] = "Hello i AM parent";  
    char child_message[] = "Hello i am child!";
    char buffer[100];

    if (pipe(pipefd1) == -1 || pipe(pipefd2) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);   //error aa jyega
    }

    if (pid == 0) {        // child process mei he
        close(pipefd1[1]);  // Close write end of P1 CW  1 means the right end;
        close(pipefd2[0]); // close the read end of P2  

        read(pipefd1[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);

        write(pipefd2[1], child_message, strlen(child_message) + 1);

        close(pipefd1[0]);  // JO UPAR CLOSE ni kara tha ab use close kar diya ;
        close(pipefd2[1]);
    } else {
        close(pipefd1[0]);
        close(pipefd2[1]);

        write(pipefd1[1], parent_message, strlen(parent_message) + 1);

        read(pipefd2[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);

        close(pipefd1[1]);
        close(pipefd2[0]);
    }

    return 0;
}


/*
Child received: Hello i AM parent
Parent received: Hello i am child!
*/
