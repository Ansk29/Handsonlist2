#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *fifo_path = "/home/anshul-kakirde/Handsonlist 2/Solutions/Q20/myfifo";
    int fd;
    const char *message = "Hello from writer!";

    fd = open(fifo_path, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    write(fd, message, strlen(message) + 1);
    close(fd);

    return 0;
}

