#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define FIFO_NAME "myfifo"

int main() {
    // Creating FIFO file using mknod system call
    if (mknod(FIFO_NAME, S_IFIFO | 0666, 0) == -1) {
        perror("mknod");
        exit(EXIT_FAILURE);
    }
    printf("FIFO file created using mknod\n");

    // Creating FIFO file using mkfifo library function
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }
    printf("FIFO file created using mkfifo\n");

    // Remove the FIFO file
    if (unlink(FIFO_NAME) == -1) {
        perror("unlink");
        exit(EXIT_FAILURE);
    }
    printf("FIFO file removed\n");

    return 0;
}

