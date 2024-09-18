/*
============================================================================
Name : 26.c
Author : Anshul Kakirde
Description :rite a program to send messages to the message queue. Check $ipcs
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
    int msgid = msgget(key, 0666 | IPC_CREAT);
    struct msgbuf message;

    message.mtype = 1;
    strncpy(message.mtext, "Hello, this is a message.", MSG_SIZE);

    if (msgsnd(msgid, &message, sizeof(message.mtext), 0) == -1) {
        perror("msgsnd");
        exit(1);
    }

    printf("Message sent to queue %d\n", msgid);
    return 0;
}


/*Message sent to queue 0/*
