#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    int rw[2];
    pipe(rw);
    if (fork() != 0) {
        close(rw[1]);
        char str[1024];
        read(rw[0], str, 1024);
        printf("%s", str);
        close(rw[0]);
        return EXIT_SUCCESS;
    }
    close(rw[0]);
    char str[1024];
    fgets(str, 1024, stdin);
    write(rw[0], str, strlen(str) + 1);
    wait(NULL);
    exit(EXIT_SUCCESS);
}

