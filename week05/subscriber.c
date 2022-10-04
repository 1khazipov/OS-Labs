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
    printf("Subscriber id: %d\n", n);
    char *name = "/tmp/ex1";
    mkfifo(name, 0666);
    char str[1024] = "";
    while (1) {
        int rw1 = open(name, O_RDONLY);
        read(rw1, str, 1024);
        close(rw1);
        if (str[0] - '0' == n) printf("Message: %s", str + 1);
        else {
            int rw2 = open (name, O_WRONLY);
            write(rw2, str, strlen(str) + 1);
            close(rw2);
        }
        str[0] = '\0';
    }

    return EXIT_SUCCESS;
}
