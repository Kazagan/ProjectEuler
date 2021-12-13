#include <stdio.h>

#define MAX_SIZE 302
#define EXPONENT 1000

int main(void) {
    int number[MAX_SIZE] = {0};
    number[0] = 1;
    int temp;
    int carry;

    for(int i = 0; i < EXPONENT; i++) {
        carry = 0;
        for(int j = 0; j < MAX_SIZE; j++) {
            temp = (2 * number[j]) + carry;
            carry = (temp > 0) ?  (temp / 10) : 0;
            number[j] = temp % 10;
        }
    }

    int sum = 0;
    for(int i = 0; i < MAX_SIZE; i++)
        sum += number[i];

    printf("%d\n", sum);

    return 0;
}

/*
 *
 * Don't really feel like downloading a large int library so gotta figure out how to
 * handle the number with an array.
 *
 *  2, 0, 0, 0, 0, 0, 0, 0, 0, 0
 *  4, 0 ,0 ,0, 0, 0, 0 ,0, 0, 0
 *  8, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0
 *  16
 *  6, 1, 0, 0, 0, 0 ,0 ,0 ,0 ,0
 *
 *  So I should be able to build it backwards, and add them that way.
 */