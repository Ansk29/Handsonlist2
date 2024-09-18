/*
============================================================================
Name : 30.c
Author : Anshul Kakirde
Description: . . Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory
Date: , 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

int main() {
    key_t key = ftok("progfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    char *data = (char *)shmat(shmid, NULL, 0);
    if (data == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }

    strncpy(data, "Hello, Shared Memory!", 1024);

    char *read_only_data = (char *)shmat(shmid, NULL, SHM_RDONLY);
    if (read_only_data == (char *)(-1)) {
        perror("shmat with O_RDONLY");
        exit(1);
    }

    printf("Data read: %s\n", read_only_data);

    if (shmdt(read_only_data) == -1) {
        perror("shmdt");
        exit(1);
    }

    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(1);
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}


/*Data read: Hello, Shared Memory!*/
