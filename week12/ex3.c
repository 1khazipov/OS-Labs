#include <stdio.h>
#include <dirent.h>
#include <linux/input.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    printf("The available shortcuts:\np+e--> I passed the Exam\nc+a+p--> Get some cappuccino!\nq+w--> Good\n");
    int array[100];
    char *d = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    int f = open(d, O_RDONLY);
    if (f < 0) {
        return 0;
    } else {
        while (1) {
            struct input_event inputEvent;
            read(f, &inputEvent, sizeof(inputEvent));
            if (inputEvent.type == EV_KEY) {
                array[inputEvent.code] = inputEvent.value;
                if (array[25] == 2 && array[18] == 2 || array[25] == 1 && array[18] == 1)
                    printf("I passed the Exam!\n");
                if (array[46] == 2 && array[30] == 2 && array[25] == 2 ||
                    array[46] == 1 && array[30] == 1 && array[25] == 1)
                    printf("“Get some cappuccino!\n");
            }
            if (array[16] == 2 && array[17] == 2 || array[16] == 1 && array[17] == 1)
                printf("Good\n");
        }
    }
    return 0;
}
