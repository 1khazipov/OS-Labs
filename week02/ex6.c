#include <stdio.h>
#include <stdlib.h>

void pattern1(int num) {
    printf("\nFirst pattern:\n");
    char* line1 = (char*) calloc(256, sizeof(char));
    for (int i = 0; i < num; i++) {
        line1[i] = '*';
        printf("%s\n", line1);
    }
    free(line1);
}

void pattern2(int num) {
    printf("\nSecond pattern:\n");
    char* line2 = (char*) calloc(256, sizeof(char));
    for (int i = 0; i < (num + 1) / 2; i++) {
        line2[i] = '*';
        printf("%s\n", line2);
    }
    if (num % 2 != 0) {
        for (int i = num - 1; i >= (num + 1) / 2; i--) {
            line2[i - num / 2] = '\0';
            printf("%s\n", line2);
        }
    }
    else {
        for (int i = num - 1; i >= num / 2 - 1; i--) {
            printf("%s\n", line2);
            line2[i - num / 2] = '\0';
        }
    }
    free(line2);
}

void pattern3(int num) {
    printf("\nThird pattern:\n");
    char* line3 = (char*) calloc(256, sizeof(char));
    for (int i = 0; i < num; i++) {
        line3[i] = '*';
    }
    for (int i = 0; i < num; i++) {
        printf("%s\n", line3);
    }
    free(line3);
}

int main() {
    int num;
    printf("Type a number of lines: ");
    scanf("%d", &num);
    pattern1(num);
    pattern2(num);
    pattern3(num);
    return 0;
}
