/*
============================================================================
Name : 25.c
Author : Anshul Kakirde
Description :  Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date: , 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    key_t key = ftok("progfile", 65);
    int msgid = msgget(key, 0666);

    if (msgid == -1) {
        perror("msgget");
        return 1;
    }

    struct msqid_ds msq_info;
    if (msgctl(msgid, IPC_STAT, &msq_info) == -1) {
        perror("msgctl");
        return 1;
    }

    printf("Access Permissions: %o\n", msq_info.msg_perm.mode & 0777);
    printf("UID: %d\n", msq_info.msg_perm.uid);
    printf("GID: %d\n", msq_info.msg_perm.gid);
    printf("Time of Last Message Sent: %s", ctime(&msq_info.msg_stime));
    printf("Time of Last Message Received: %s", ctime(&msq_info.msg_rtime));
    printf("Time of Last Change: %s", ctime(&msq_info.msg_ctime));
    printf("Size of the Queue: %ld bytes\n", msq_info.msg_qbytes);
    printf("Number of Messages: %lu\n", msq_info.msg_qnum);
    printf("Maximum Number of Bytes Allowed: %ld\n", msq_info.msg_qbytes);
    printf("PID of Last Message Sent: %d\n", msq_info.msg_lspid);
    printf("PID of Last Message Received: %d\n", msq_info.msg_lrpid);

    return 0;
}


/*Access Permissions: 666
UID: 1000
GID: 1000
Time of Last Message Sent: Thu Jan  1 05:30:00 1970
Time of Last Message Received: Thu Jan  1 05:30:00 1970
Time of Last Change: Wed Sep 18 00:35:30 2024
Size of the Queue: 16384 bytes
Number of Messages: 0
Maximum Number of Bytes Allowed: 16384
PID of Last Message Sent: 0
PID of Last Message Received: 0*/

