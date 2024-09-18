/*
============================================================================
Name : 4.c
Author : Anshul Kakirde
Description : Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
Date: 16th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>

static inline uint64_t rdtsc() {
    unsigned int lo, hi;
    __asm__ __volatile__("rdtsc" : "=a"(lo), "=d"(hi));
    return ((uint64_t)hi << 32) | lo;
}

int main(void) {
    uint64_t start, end;
    pid_t ppid;
    int i;

    start = rdtsc();

    for (i = 0; i < 100; i++) {
        ppid = getppid();
    }

    end = rdtsc();

    printf("Time taken for 100 getppid() is %lu \n", end - start); // cycles mein value ;

    return 0;
}


/*Time taken for 100 getppid() is 131418 */
