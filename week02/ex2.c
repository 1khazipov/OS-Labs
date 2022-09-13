#include <stdio.h>
#include <string.h>

int dotPosition(const char text[256]) {
    int pos = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == '.') {
            pos = i;
            break;
        }
    }
    if (pos == 0) pos = strlen(text);
    return pos;
}

void printReverse(int pos, const char text[256]) {
    printf("\"");
    for (int i = pos - 1; i >= 0; i--)
        printf("%c", text[i]);
    printf("\"");
}

int main() {
    printf("Type a string here: ");
    char text[256];
    fgets(text, 256, stdin);
    if (text[strlen(text) - 1] == '\n')
        text[strlen(text) - 1] = '\0';
    printReverse(dotPosition(text), text);
    return 0;
}
