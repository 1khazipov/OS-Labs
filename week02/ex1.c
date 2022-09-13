#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int var1;
    unsigned short int var2;
    signed long int var3;
    float var4;
    double var5;
    var1 = INT_MAX;
    var2 = USHRT_MAX;
    var3 = LONG_MAX;
    var4 = FLT_MAX;
    var5 = DBL_MAX;
    printf("Size and value for integer:\n");
    printf("%lu %d\n\n", sizeof(var1), var1);
    printf("Size and value for unsigned short integer:\n");
    printf("%lu %d\n\n", sizeof(var2), var2);
    printf("Size and value for signed long int:\n");
    printf("%lu %ld\n\n", sizeof(var3), var3);
    printf("Size and value for float:\n");
    printf("%lu %f\n\n", sizeof(var4), var4);
    printf("Size and value for double:\n");
    printf("%lu %f\n\n", sizeof(var5), var5);
    return 0;
}
