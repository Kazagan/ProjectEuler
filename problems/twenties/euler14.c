#include <stdio.h>

#define UPPER_BOUND 1000000
#define MAX(x,y) (x < y) ? y : x
#define IS_EVEN(x) ( x % 2 == 0 )

int collatz(long long n) {
    int count = 0;
    while( n != 1 ) {
        n = ( IS_EVEN(n) ) ? (n /  2) : ((n * 3) + 1);
        count++;
    }
    return count;
}

int main(void) {
    long long greatest = 0;

    for(long long i = 1; i < UPPER_BOUND; i++) { // skip even numbers
        int count = collatz(i);
        if(count > greatest)
            printf("%lld COUNT: %d \n", i, count);
        greatest = MAX(greatest, count);
    }
    printf("%lld \n", greatest);
    return 0;
}


/*
 *
 *  So  We're looking at Collatz_conjecture, which states:
 *      FOR N
 *          IS EVEN DIVIDE BY 2
 *          IS ODD MULTIPLY BY 3 ADD 1
 *
 *  So we could brute force this, and just check every number, but this is going to be slow.
 *
 *  Doing some research into optimizations it appears numbers can be skipped if they follow predefined rules of modulo
 *
 */