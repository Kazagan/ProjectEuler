#include <stdio.h>
#include <stdlib.h>

int sum_divisors(int n);

int main() {   
    int sum = 0;
    for(int i = 1; i < 10000; i++) {   
        int first_sum = sum_divisors(i);
        if(first_sum != i && sum_divisors(first_sum) == i) {
            printf("%d\n", first_sum);
            sum += i;
        }
    }
    printf("sum = %d\n", sum);
    return 0;
}

int sum_divisors(int n) {
    int sum = 0;
    for(int i = 1; i <= n/2; i++) {
        if(n % i == 0) {
            sum += i;
        }
    }
    return sum;
}

