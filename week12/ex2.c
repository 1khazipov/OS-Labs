#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <linux/input.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int input = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    while(1) {
        struct input_event inputEvent;
        if (read(input, (void*) &inputEvent, sizeof(struct input_event)) < sizeof(struct input_event)) continue;
        if (inputEvent.type == 1) printf("PRESSED %x (%d)\n", inputEvent.code, inputEvent.code);
        else if (inputEvent.type == 0) printf("RELEASED %x (%d)\n", inputEvent.code, inputEvent.code);
    }
    exit(EXIT_SUCCESS);
}
