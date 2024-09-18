#include <sys/time.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void timer_handler(int signum) {
    printf("ITIMER_VIRTUAL Timer 10sec time is over\n");
}

int main(void) {
    struct itimerval timer;

    
    signal(SIGVTALRM, timer_handler);

    
    timer.it_value.tv_sec = 10;     
    timer.it_value.tv_usec = 10;    
    timer.it_interval.tv_sec = 10;  
    timer.it_interval.tv_usec = 10; 

    
    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    
  while (1) {
        // ye wali condition add kara h ekyuki is baar humne jo he virtual timer use kara he cpu ko busy rakhne ke liye ;
        for (int i = 0; i < 100000000; i++) {
            
        }
    }
    return 0;
}

/*
(timing)
1 
2
3
4
5
6
7
8
9
10
ITIMER_VIRTUAL Timer 10sec time is over

*/
