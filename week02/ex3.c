#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long long int power(long long int num, int p) {
    long long newNum = 1;
    if (p == 0) return 1;
    while (p > 0) {
        newNum *= num;
        p--;
    }
    return newNum;
}

void convert(const char num[256], int sysFrom, int sysTo) {
    if (sysFrom < 2 || sysTo < 2 || sysFrom > 10 || sysTo > 10) {
        printf("cannot convert!");
        exit(0);
    }
    long long int decimal = 0;
    for (int i = strlen(num) - 1; i >= 0 ; i--) {
        if ((num[i] - '0') % 10 >= sysFrom) {
            printf("cannot convert!");
            exit(0);
        }
        decimal += power(sysFrom, strlen(num) - i - 1) * (num[i] - '0');
    }
    if (decimal == 0) {
        printf("0");
        return;
    }
    char toRet[256];
    int i = 0;
    while (decimal != 0) {
        toRet[i] = (char) ((decimal % sysTo) + '0');
        decimal /= sysTo;
        i++;
    }
    toRet[i] = '\0';
    for (i = 0; i < strlen(toRet) / 2; i++) {
        char temp = toRet[strlen(toRet) - i - 1];
        toRet[strlen(toRet) - i - 1] = toRet[i];
        toRet[i] = temp;
    }
    printf("%s", toRet);
}

int main() {
    char number[256];
    printf("Type a number: ");
    fgets(number, 256, stdin);
    size_t length = strlen(number) - 1;
    if (number[length] == '\n') {
        number[length] = '\0';
    }
    int sysFrom, sysTo;
    printf("Type an initial system: ");
    scanf("%d", &sysFrom);
    printf("Type a final system: ");
    scanf("%d", &sysTo);
    convert(number, sysFrom, sysTo);
    return 0;
}
