#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count(char text[256], char symbol) {
    int c = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (tolower(text[i]) == tolower(symbol)) c++;
    }
    return c;
}

void countAll(char text[256]) {
    for (int i = 0; i < strlen(text); i++) {
        printf("%c:%d", tolower(text[i]), count(text, text[i]));
        if (i != strlen(text) - 1) printf(", ");
        else printf("\n");
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Incorrect number of arguments!");
        return 0;
    }
    char *text = argv[1];
    if (text[strlen(text) - 1] == '\n')
        text[strlen(text) - 1] = '\0';
    countAll(text);
    return 0;
}
