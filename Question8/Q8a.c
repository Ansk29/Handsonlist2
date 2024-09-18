#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler(int signum) {
    if (signum == SIGSEGV) {
        printf("Caught SIGSEGV\n");
        exit(1);
    }
}

int main(void) {
    signal(SIGSEGV, signal_handler);

    // Deliberately cause a segmentation fault
    int *ptr = NULL;
    *ptr = 42;

    return 0;
}

