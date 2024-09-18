#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler(int signum) {
    if (signum == SIGFPE) {
        printf("Caught SIGFPE\n");
        exit(1);
    }
}

int main(void) {
    signal(SIGFPE, signal_handler);

    // Deliberately cause a floating-point exception
    int a = 1, b = 0;
    int c = a / b; // Division by zero

    return 0;
}

