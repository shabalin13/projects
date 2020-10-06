#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zconf.h>
#include <sys/resource.h>

int main() {
    struct rusage r_usage;
    int memorySize = 10*1024*1024;
    for (int i = 0; i < 10; ++i) {
        void *ptr = malloc(memorySize); //allocate 10 MB of memory
        memset(ptr, 0, memorySize); //fill it with zeros
        getrusage(RUSAGE_SELF, &r_usage);
        printf("ru_maxrss: %ld\n", r_usage.ru_maxrss); //print memory usage
        sleep(1); //sleep for 1 second
    }
    return 0;
}