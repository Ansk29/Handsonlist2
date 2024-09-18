/*
============================================================================
Name : 28.c
Author : Anshul Kakirde
Description: Write a program to change the exiting message queue permission. (use msqid_ds structure)
Date: , 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

int main() {
    key_t key = ftok("progfile", 65);
    int msgid = msgget(key, 0666);

    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    struct msqid_ds msq_info;
    if (msgctl(msgid, IPC_STAT, &msq_info) == -1) {
        perror("msgctl IPC_STAT");
        exit(1);
    }

    msq_info.msg_perm.mode = 0660;

    if (msgctl(msgid, IPC_SET, &msq_info) == -1) {
        perror("msgctl IPC_SET");
        exit(1);
    }

    printf("Permissions changed successfully\n");

    return 0;
}


/*Permissions changed successfully
*/
