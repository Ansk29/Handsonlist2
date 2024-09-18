/*
============================================================================
Name : 227.c
Author : Anshul Kakirde
Description: . Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO.
Date: , 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSG_SIZE 100

struct msgbuf {
    long mtype;
    char mtext[MSG_SIZE];
};

int main() {
    key_t key = ftok("progfile", 65);
    int msgid = msgget(key, 0666);
    struct msgbuf message;

    if (msgrcv(msgid, &message, sizeof(message.mtext), 1, 0) != -1) {
        printf("Received with flag 0: %s\n", message.mtext);
    } else {
        perror("msgrcv");
    }

    if (msgrcv(msgid, &message, sizeof(message.mtext), 1, IPC_NOWAIT) != -1) {
        printf("Received with IPC_NOWAIT: %s\n", message.mtext);
    } else {
        perror("msgrcv");
    }

    return 0;
}


/*Received with flag 0: Hello, this is a message.
msgrcv: No message of desired type*/

