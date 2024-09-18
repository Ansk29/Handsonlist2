/*
============================================================================
Name : 12.c
Author : Anshul Kakirde
Description :Write a program to create an orphan process. Use kill system call to send SIGKILL signal to the parent process from the child process. signal - Use signal system call.
Date: , 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        printf("Child process PID is %d\n", getpid());
        printf("Child process using SIGKILL on the parent (PID: %d)\n", getppid());
        kill(getppid(), SIGKILL);
        sleep(5); ///pehle hi na terminate ho jaye kill karne ke ensures ke poora enouhg time mile
        printf("Child process: I am now an orphan, my new parent is init (PID: 1)\n");
    } else {
        printf("Parent process: My PID is %d, and my child's PID is %d\n", getpid(), pid);
        sleep(10); // parent procwss na jaldi khtm ho jye child ko time hi na mile.
    }

    return 0;
}

