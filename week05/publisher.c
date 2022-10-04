#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int n;
    sscanf(argv[1], "%d", &n);
    printf("Publisher:\n");
    char *name = "/tmp/ex1";
    mkfifo(name, 0666);
    char str[1024];
    while (!feof(stdin)) {
        fgets(str + 1, 1024, stdin);
        for (int i = 0; i < n; i++) {
            str[0] = (char) ('0' + i);
            int rw = open (name, O_WRONLY);
            write(rw, str, strlen(str) + 1);
            close(rw);
            usleep(100000);
        }
        sleep(1);
    }
    return EXIT_SUCCESS;
}

