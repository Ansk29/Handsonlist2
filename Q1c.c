#include <sys/time.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void timer_handler(int signum) {
    printf("ITIMER_PROF Timer has expired after 10 sec!\n");
}

int main(void) {
    struct itimerval timer;

    
    signal(SIGPROF, timer_handler);

    
    timer.it_value.tv_sec = 10;     
    timer.it_value.tv_usec = 10;    
    timer.it_interval.tv_sec = 10;  
    timer.it_interval.tv_usec = 10; 

  
    setitimer(ITIMER_PROF, &timer, NULL);

    
    while (1) {
        
        for (int i = 0; i < 100000000; i++) {
            //  (keeps CPU busy in user-space)
        }

        

    }

    return 0;
}


/*










ITIMER_PROF Timer has expired after 10 sec!
*/
