#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <string.h>

typedef struct {
    pthread_t id;
    int i;
    char message[256];
} Thread;

void *func(void *arg) {
    Thread *request = (Thread *) arg;
    printf("id: %lu\n", request->id);
    printf("message: %s\n", request->message);
    pthread_exit(NULL);
}

int main() {
    Thread *array = malloc(256 * sizeof(Thread));
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        array[i].i = i;
        sprintf(array[i].message, "Hello from thread %d\n", i);
        pthread_create(&array[i].id, NULL, func, &array[i]);
        printf("Thread %d is created\n", i);
        pthread_join(array[i].id, NULL);
    }
    return EXIT_SUCCESS;
}
