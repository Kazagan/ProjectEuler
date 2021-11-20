#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define DEFAULT_SIZE 2000000

int is_prime(long n) {
    if(n == 1)
        return 0;
    if(n < 4)
        return 1;
    if(n % 2 == 0)
        return 0;
    if(n < 9)
        return 1;
    if(n % 3 == 0)
        return 0;
    long x = sqrtl(n);
    for(long i = 5; i <= x; i += 6) {
        if(n % i == 0)
            return 0;
        if(n % (i + 2) == 0)
            return 0;
    }
    return 1;
}

long long get_primes_erat(long n) {
    float startTime = (float)clock()/CLOCKS_PER_SEC;
    long sum = 2 + 3 + 5 + 7; // Start with first few easily known primes, loop starts at 9
    for(long i = 9; i < n; i+=2) {
        if(is_prime(i))
            sum += i;
    }

    float timeElapsed = ((float)clock()/CLOCKS_PER_SEC) - startTime;
    printf("it Took erat: %f\n", timeElapsed);
    return sum;
}

long long get_primes_array(long n) {
    
    float startTime = (float)clock()/CLOCKS_PER_SEC;
    /* long *primes = malloc((n / 10)* sizeof *primes); */
    
    long primes[n/10]; 
    primes[0] = 2;
    primes[1] = 3;
    primes[2] = 5;
    primes[3] = 7;
    long count = 4;
    long long sum = 2 + 3 + 5 + 7;

    for(long i = 9; i < n; i += 2) {
        int is_prime = 1;
        long x = sqrtl(i);
        for(long j = 0; primes[j] <= x; j++) {
            if(i % primes[j] == 0) {
                is_prime = 0;
                break;
            }
        }
        if(is_prime) {
            primes[count] = i;
            count++;
            sum += i;
        }
    }
    float timeElapsed = ((float)clock()/CLOCKS_PER_SEC) - startTime;
    printf("it Took erat: %f\n", timeElapsed);
    return sum;
}

int main(int argc, char *argv[]) {
    /* printf("%ld\n", atol(argv[1])); */
    long size = (argc != 2) ? DEFAULT_SIZE : atol(argv[1]);
    long long x = get_primes_erat(size);
    long long y  = get_primes_array(size);
    printf("answer: %lld : %lld \n", x, y);
    return 0;
}
