#include <stdio.h>

#define sqr(x) ((x) * (x))

int main() {
    int n = 100;
    long sum1 = 0;
    long sum2 = 0;
    for(int i = 1; i <= n; i++) {
        sum1 += sqr(i);
        sum2 += i;
    }
    long result = sqr(sum2) - sum1;
    printf("%ld\n", result);
    return 1;
}
