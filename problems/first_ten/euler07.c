#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

#define MAX_PRIMES 10001
/* #define sqr(x) x*x */

void die(const char *message) {
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }
    exit(1);
}

int main() {
    int primes[MAX_PRIMES];
    primes[0] = 2;
    primes[1] = 3;
    primes[2] = 5;
    primes[3] = 7;
    int count = 4;
    
    for(int i = 8; i < INT_MAX; i++) {
        int is_prime = 1;
        for(int j = 0; j < count; j ++) {
           if ( i % primes[j] == 0) {
                is_prime = 0;
                break;
            }
        }
        if(is_prime) {
            primes[count] = i;
            count++;
        }
        if(count == MAX_PRIMES)
            break;
    }
    printf("%d, %d\n", primes[count-1], count);
    return 0;
}
