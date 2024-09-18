/*
============================================================================
Name : 5.c
Author : Anshul Kakirde
Description : 5. Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.
Date:  2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/resource.h>
#include <sys/sysinfo.h>

int main(void) {
    // a. Maximum length of arguments to exec family
    printf("Maximum length of arguments to exec family: %ld bytes\n", sysconf(_SC_ARG_MAX));

    // b. Maximum number of simultaneous processes per user ID
    printf("Maximum number of simultaneous processes per user ID: %ld\n", sysconf(_SC_CHILD_MAX));

    // c. Number of clock ticks (jiffy) per second
    printf("Number of clock ticks (jiffy) per second: %ld\n", sysconf(_SC_CLK_TCK));

    // d. Maximum number of open files
    struct rlimit limit;
    getrlimit(RLIMIT_NOFILE, &limit);
    printf("Maximum number of open files: %ld\n", (long)limit.rlim_max);

    // e. Size of a page
    printf("Size of a page: %ld bytes\n", sysconf(_SC_PAGESIZE));

    // f. Total number of pages in the physical memory
    struct sysinfo info;
    sysinfo(&info);
    printf("Total number of pages in the physical memory: %ld\n", info.totalram / sysconf(_SC_PAGESIZE));

    // g. Number of currently available pages in the physical memory
    printf("Number of currently available pages in the physical memory: %ld\n", info.freeram / sysconf(_SC_PAGESIZE));

    return 0;
}

/*Maximum length of arguments to exec family: 2097152 bytes
Maximum number of simultaneous processes per user ID: 23152
Number of clock ticks (jiffy) per second: 100
Maximum number of open files: 1048576
Size of a page: 4096 bytes
Total number of pages in the physical memory: 1500505
Number of currently available pages in the physical memory: 307000*/


