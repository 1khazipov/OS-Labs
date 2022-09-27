#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
    int n;
    printf("Type number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        fork();
        sleep(5);
    }
    return EXIT_SUCCESS;
}

