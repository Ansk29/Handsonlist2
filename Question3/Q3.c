/*
============================================================================
Name : 3.c
Author : Anshul Kakirde
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
Date : 
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
    struct rlimit rlim;
    
   
    if (getrlimit(RLIMIT_NOFILE, &rlim) == -1) {Write a program to set (any one) system resource limit. Use setrlimit system call.
        perror("getrlimit");
        return 1;
    }
    printf("Before setting new limit:\n");
    printf("Soft limit: %ld\n", (long)rlim.rlim_cur);
    printf("Hard limit: %ld\n", (long)rlim.rlim_max);

    
    rlim.rlim_cur = 512;  
    rlim.rlim_max = 1024;  

    // Settinig the new limits
    if (setrlimit(RLIMIT_NOFILE, &rlim) == -1) {
        perror("setrlimit");
        return 1;
    }
    
  
  if (getrlimit(RLIMIT_NOFILE, &rlim) == -1) {
        perror("getrlimit");
        return 1;
    }
    printf("After setting new limit:\n");
    printf("Soft limit: %ld\n", (long)rlim.rlim_cur);
    printf("Hard limit: %ld\n", (long)rlim.rlim_max);


    return 0;
}


/*
Before setting new limit:
Soft limit: 1024
Hard limit: 1048576
After setting new limit:
Soft limit: 512
Hard limit: 1024
*/
