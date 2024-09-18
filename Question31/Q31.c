/*
============================================================================
Name : 31.c
Author : Anshul Kakirde
Description: . . Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
b. create a counting semaphore
Date: , 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int main() {
    sem_t binary_sem;
    sem_t counting_sem;

    
    if (sem_init(&binary_sem, 0, 1) == -1) {
        perror("binary");
        exit(1);
    }

    
    if (sem_init(&counting_sem, 0, 5) == -1) {
        perror("counting");
        exit(1);
    }

    printf("Binary semaphore and counting semaphore initialized successfully.\n");

    // Clean up
    if (sem_destroy(&binary_sem) == -1) {
        perror("binary");
        exit(1);
    }

    if (sem_destroy(&counting_sem) == -1) {
        perror("counting");
        exit(1);
    }

    return 0;
}

/*Binary semaphore and counting semaphore initialized successfully.
*/
