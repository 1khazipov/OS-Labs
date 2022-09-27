#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "time.h"
#include <sys/wait.h>

int main() {
    if (fork() == 0) {
        clock_t start_t_2 = clock();
        printf("First child process: pid: %d parent pid: %d\n", getpid(), getppid());
        clock_t end_t_2 = clock();
        printf("First child time: %f ms\n", (double) (end_t_2 - start_t_2));
        exit(EXIT_SUCCESS);
    }
    else {
        if (fork() == 0) {
            clock_t start_t_3, end_t_3;
            start_t_3 = clock();
            printf("Second child process: pid: %d parent pid: %d\n", getpid(), getppid());
            end_t_3 = clock();
            printf("Second child time: %f ms\n", (double) (end_t_3 - start_t_3));
            exit(EXIT_SUCCESS);
        }
    }
    clock_t start_t_1, end_t_1;
    start_t_1 = clock();
    while (wait(NULL) != -1) {}
    printf("Main process: pid: %d parent pid: %d\n", getpid(), getppid());
    end_t_1 = clock();
    printf("Main process time: %f ms\n", (double) (end_t_1 - start_t_1));
    return EXIT_SUCCESS;
}
