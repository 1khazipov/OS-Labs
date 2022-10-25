#include "stdio.h"
#include <stdlib.h>

int main() {
    printf("Type N: ");
    int N;
    scanf("%d", &N);
    int *array = calloc(N, sizeof(int));

    for (int i = 0; i < N; i++)
        array[i] = i;

    printf("array: ");
    for (int i = 0; i < N; i++)
        printf("%d ", array[i]);

    free(array);
    return EXIT_SUCCESS;
}
