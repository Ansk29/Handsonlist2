#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd1, fd2;
    const char *message1 = "Hello from writer!";
    char buffer[100];

    fd1 = open("/home/anshul-kakirde/Handsonlist 2/Solutions/fifo1", O_WRONLY);
    fd2 = open("/home/anshul-kakirde/Handsonlist 2/Solutions/fifo2", O_RDONLY);

    write(fd1, message1, strlen(message1) + 1);
    close(fd1);

    read(fd2, buffer, sizeof(buffer));
    printf("Writer received: %s\n", buffer);
    close(fd2);

    return 0;
}


/*Writer received: Hello from reader!
*/
