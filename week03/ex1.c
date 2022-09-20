#include "stdio.h"
#include <stdlib.h>

int foo(const int* age) {
    return 2022 - *age;
}

int main() {
    const int x = 10;
    const int* q = &x;
    const int* const p = (const int*) calloc(5, sizeof(const int));
    for (int i = 0; i < 5; i++) {
        printf("%p ", p + i);
    }
    printf("\n");
    for (int i = 0; i < 5; i++) {
        int* temp = (int *) p + i;
        *temp = x;
    }
    printf("Enter ages: ");
    for (int i = 0; i < 5; i++) {
        int* temp = (int *) p + i;
        int temp2;
        scanf("%d", &temp2);
        *temp = temp2;
    }
    for (int i = 0; i < 5; i++) {
        int* temp = (int *) p + i;
        *temp = foo(temp);
        printf("%d ", *(p + i));
    }
    free((void *) p);
    return 0;
}
