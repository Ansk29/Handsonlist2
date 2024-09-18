#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
    struct rlimit rlim;
    int ret;

    // Get the limit on core dump file size
    ret = getrlimit(RLIMIT_CORE, &rlim);
    if (ret == -1) {
        perror("getrlimit");
        return 1; // Return with an error code if getrlimit fails
    }

    
    printf("RLIMIT_CORE limits: soft=%ld hard=%ld\n", (long)rlim.rlim_cur, (long)rlim.rlim_max);

    return 0;
}
