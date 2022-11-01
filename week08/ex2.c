#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main() {
    const int mem = 2500000;
    for (int i = 0; i < 10; i++) {
        int *array = calloc(mem, sizeof(int));
        memset(array, 0, mem);
        sleep(1);
    }
    return 0;
}

/**
 * si = 0: memory swapped from disk.
 * so = 0: memory swapped to disk.
 * I have enough memory in my laptop, therefore si = so = 0.
 * My program reduces the memory every second for 10 seconds, so my program works correctly.
 * When I ran my program, I saw that PID, CPU usage, CPU time, RAM usage total memory,
 * total virtual memory, and memory usage were changed.
 */
