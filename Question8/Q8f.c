#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

void signal_handler(int signum) {
    if (signum == SIGVTALRM) {
        printf("Caught SIGVTALRM\n");
        exit(1);
    }
}

int main(void) {
    struct itimerval timer;

    signal(SIGVTALRM, signal_handler);

    // Configure the timer
    timer.it_value.tv_sec = 5;     // Set initial expiration time to 5 seconds
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;  // No repeated intervals
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    // Wait indefinitely until the signal is received
    while (1) {
        pause();
    }

    return 0;
}
s
