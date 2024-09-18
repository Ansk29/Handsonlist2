#include <stdio.h>
#include <sys/resource.h>
#include <limits.h>

void resource(const char *resource_name, int resource) {
    struct rlimit limit;

    // Get the current resource limits
    if (getrlimit(resource, &limit) == 0) {
        printf("%s:\n", resource_name);
        printf("  Soft limit: %ld\n", (long)limit.rlim_cur);
        printf("  Hard limit: %ld\n", (long)limit.rlim_max);
    } else {
        perror("getrlimit");
    }
}

int main(void) {
    // Print various resource limits

    // max size of a file 
    resource("File size", RLIMIT_FSIZE);

    // max fd
    resource("Open files", RLIMIT_NOFILE);

    // Maximum cpu time
    resource("CPU time", RLIMIT_CPU);


    // Maximum number of processes that can be created
    resource("Max processes", RLIMIT_NPROC);

    // Maximum size of a stack
    resource("Stack size", RLIMIT_STACK);

    return 0;
}

/*
File size:
  Soft limit: -1
  Hard limit: -1
Open files:
  Soft limit: 1024
  Hard limit: 1048576
CPU time:
  Soft limit: -1
  Hard limit: -1
Max processes:
  Soft limit: 23152
  Hard limit: 23152
Stack size:
  Soft limit: 8388608
  Hard limit: -1
*/
