/*
============================================================================
Name : 1a.c
Author : Anshul Kakirde
Description:1. Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
Date: 19 sept , 2024.
============================================================================
*/

#include <sys/time.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void timer_handler(int signum) {
    printf("ITIMER_REALTimer 10sec time is over\n");
}

int main(void) {
    struct itimerval timer;

   
    signal(SIGALRM, timer_handler); // kya milega signal aur kya karna he uske milne par ;

    // Configure the timer
    timer.it_value.tv_sec = 10;     // expiry time in second
    timer.it_value.tv_usec = 10;    // 
    timer.it_interval.tv_sec = 10;  // 
    timer.it_interval.tv_usec = 10; // expiry ke baad naya aalarm kitne interval mei

    // Set the interval timer
    setitimer(ITIMER_REAL, &timer, NULL);

    // Wait for signals
    while (1) {
        pause(); //jab tak signal nhi milta program ko rokne ke liye;
    }

    return 0;
}


/*Output
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
ITIMER_REALTimer 10sec time is over


aur har 10 sec ke bad ye same print karte hi jayega kyuki meine time interval do alarm k beech ka ten sec de rakha he
*/
