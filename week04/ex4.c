#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>

int main() {
    while (true) {
        char cmd[256];
        printf("> ");
        fgets(cmd, 256, stdin);
        if (cmd[0] == 'e' && cmd[1] == 'x' && cmd[2] == 'i' && cmd[3] == 't')
            return EXIT_SUCCESS;
        if (cmd[strlen(cmd) - 1] == '\n')
            cmd[strlen(cmd) - 1] = '\0';
        if (fork() == 0) {
            system(cmd);
            return EXIT_SUCCESS;
        }
        wait(NULL);
    }
}
