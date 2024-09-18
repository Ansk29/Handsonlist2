#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd1, fd2;
    const char *message2 = "Hello from reader!";
    char buffer[100];

    fd1 = open("/home/anshul-kakirde/Handsonlist 2/Solutions/fifo1", O_RDONLY);
    fd2 = open("/home/anshul-kakirde/Handsonlist 2/Solutions/fifo2", O_WRONLY);

    read(fd1, buffer, sizeof(buffer));
    printf("Reader received: %s\n", buffer);
    close(fd1);

    write(fd2, message2, strlen(message2) + 1);
    close(fd2);

    return 0;
}


/*Reader received: Hello from writer!
*/
