/*
============================================================================
Name : 29.c
Author : Anshul Kakirde
Description: . 29. Write a program to remove the message queue.
Date: , 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key = ftok("progfile", 65);
    int msgid = msgget(key, 0666);

    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }

    printf("Message queue removed successfully\n");

    return 0;
}


/*Message queue removed successfully
*/
