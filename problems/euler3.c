#include <stdio.h>

int main() {
    long x = 600851475143;
    long current  = 2;
    while(x != 1) {
        if(x % current == 0) {
            printf("%ld %ld \n", x, current);
            x = x / current;
            current--;
        }
        current ++;
    }
    printf("%ld\n", current);
    return 0;
}

