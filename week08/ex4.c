#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/resource.h>
#include<unistd.h>

int main() {
    const int mem = 2500000;
    for (int i = 0; i < 10; i++) {
        int *array = calloc(mem, sizeof(int));
        memset(array, 0, mem);
        struct rusage usage;
        sleep(1);
        getrusage(RUSAGE_SELF, &usage);
        printf("%ld\n", usage.ru_maxrss);
    }
    return 0;
}
