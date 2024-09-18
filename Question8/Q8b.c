#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler(int signum) {
    if (signum == SIGINT) {
        printf("Caught SIGINT\n");
        exit(1);
    }
}

int main(void) {
    signal(SIGINT, signal_handler);

    // Wait indefinitely until a signal is received
    while (1) {
        pause();
    }

    return 0;
}

