#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void signal_handler(int signum) {
    if (signum == SIGALRM) {
        printf("Caught SIGALRM\n");
        exit(1);
    }
}

int main(void) {
    signal(SIGALRM, signal_handler);

    // Set an alarm for 5 seconds
    alarm(5);

    // Wait indefinitely until the signal is received
    while (1) {
        pause();
    }

    return 0;
}

