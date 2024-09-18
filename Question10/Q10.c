/*
============================================================================
Name : 10.c
Author : Anshul Kakirde
Description : 9. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
Date: , 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler(int signum) {
    switch(signum) {
        case SIGSEGV:
            printf("Caught SIGSEGV\n");
            exit(1);
        case SIGINT:
            printf("Caught SIGINT\n");
            exit(1);
        default:
            printf("Caught signal %d\n", signum);
    }
}

int main(void) {
    struct sigaction sa;

    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    // Setup SIGSEGV handler
    if (sigaction(SIGSEGV, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    // Setup SIGINT handler
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    // Infinite loop to keep the program running and receiving signals
    while (1) {
        pause();
    }

    return 0;
}

