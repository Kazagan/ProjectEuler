#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>

#define CIEL_DIV(x, y) x / (y - 1)

void die(char *message) {
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }
    exit(-1);
}

long triangle_number(int n) {
    int sum = 0;
    for(int i = 1; i <= n; i++)
        sum += i;

    return sum;
}

long get_factor(int factor_count) {
    int greatest = 0;
    int count = 0;
    int current = 1;
    long triangle;
    while(count < factor_count) {
        current++;
        count = 0;
        triangle = triangle_number(current);
        for(int i = 1; i < sqrtl(triangle); i++) {
            if(triangle % i == 0) {
                count += ((triangle / i) == i) ? 1 : 2;
            }
        }
        if(greatest < count) {
            greatest = count;
            printf("Current: count = %d triangle-number = %ld \n", greatest, triangle);
        }
    }
    return triangle;
}

int main(int argc, char *argv[]) {
    if(argc < 2)
        die("USAGE: euler12 <factor_count>");

    int n = atoi(argv[1]);
    int x = get_factor(n);

    printf("Triangle number: %d \n", x );
    return 0;
}

/*

    Getting factors.
    Brute Force: check every number up to half the number, and store them, if count != 500 clear it.
    Made the mistake of doing it with /2 not sqrt 2, once I fixed that, the problem was solved.


 */

