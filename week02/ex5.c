#include <stdio.h>

long long int tribonacci(int n) {
    if (n == 0) return 0;
    else if (1 <= n && n <= 2) return 1;
    long long int trib1 = 1, trib2 = 1, trib3 = 0;
    for (int i = 0; i < n - 2; i++) {
        long long int t3 = trib2;
        long long int t2 = trib1;
        trib1 = trib1 + trib2 + trib3;
        trib2 = t2;
        trib3 = t3;
    }
    return trib1;
}

int main() {
    printf("tribonacci(4): %lld\n", tribonacci(4));
    printf("tribonacci(36): %lld\n", tribonacci(36));
    return 0;
}
