/*
============================================================================
Name : 9.c
Author : Anshul Kakirde
Description : 9. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
Date: , 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum) {
    printf("SIGINT received but should be ignored.\n");
}

int main(void) {
    // Ignore SIGINT
    signal(SIGINT, SIG_IGN);

    // Pause to wait for signal
    printf("SIGINT is now ignored. Press Ctrl+C to test.\n");
    pause();

    // Reset SIGINT to default action
    signal(SIGINT, SIG_DFL);

    printf("SIGINT action reset to default.\n");

    // Pause again to see the effect
    pause();

    return 0;
}

