/*
============================================================================
Name : 22.c
Author : Anshul Kakirde
Description: . Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO.
Date: , 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    const char *fifo_path = "/home/anshul-kakirde/Handsonlist 2/Solutions/fifo1";
    int fd;
    fd_set read_fds;
    struct timeval timeout;
    char buffer[100];

    fd = open(fifo_path, O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    FD_ZERO(&read_fds);
    FD_SET(fd, &read_fds);

    timeout.tv_sec = 10;  // 10 seconds
    timeout.tv_usec = 0;

    int ret = select(fd + 1, &read_fds, NULL, NULL, &timeout);
    if (ret == -1) {
        perror("select");
        close(fd);
        exit(EXIT_FAILURE);
    } else if (ret == 0) {
        printf("No data received within 10 seconds.\n");
    } else {
        if (FD_ISSET(fd, &read_fds)) {
            read(fd, buffer, sizeof(buffer));
            printf("Data received: %s\n", buffer);
        }
    }

    close(fd);
    return 0;
}


/*Timeout: No data received in 10 seconds.*/

