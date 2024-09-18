
/*
============================================================================
Name : 10.c
Author : Anshul Kakirde
Description :  Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
Date: , 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void ignore_sigint(int sig) {
    printf("SIGINT ignored!\n");
}

int main() {
    struct sigaction sa_ignore;

    sa_ignore.sa_handler = ignore_sigint;

    sigaction(SIGINT, &sa_ignore, NULL);

    printf("SIGINT ignored. ctrl c to try .\n");
    sleep(10);

    printf("bye ignored and exit \n");
    return 0;
}

