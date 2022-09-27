#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    int n;
    printf("Type number of processes: ");
    sscanf(argv[1], "%d", &n);

    for (int i = 0; i < n; i++) {
        fork();
        sleep(5);
    }
    return EXIT_SUCCESS;
}
