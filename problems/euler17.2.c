#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUMBERS 1000
#define MAX_SIZE 50

int get_length(int n) {
    int count = 0;
    int temp = n;
    while(temp != 0) {
        temp /= 10;
        count++;
    }
    return count;
}

int translation(int n) {
    switch(n) {
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 5;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 3;
        case 7:
            return 5;
        case 8:
            return 5;
        case 9:
            return 4;
        case 10:
            return 3;
        case 11:
            return 6;
        case 12:
            return 6;
        case 13:
            return 8;
        case 14:
            return 8;
        case 15:
            return 7;
        case 16:
            return 7;
        case 17:
            return 9;
        case 18:
            return 8;
        case 19:
            return 8;
        case 20:
            return 6;
        case 30:
            return 6;
        case 40:
            return 5;
        case 50:
            return 5;
        case 60:
            return 5;
        case 70:
            return 7;
        case 80:
            return 6;
        case 90:
            return 6;
        default:
            return 0;
    }
}

int write_number(int n, int count) {
    int total = 0;
    int temp = count;
    int number = n;
    if(temp == 4) {
        return 11;
    }
    if(temp == 3) {
        total += translation(number / 100);
        total += 7;
        if(number % 100 != 0) {
            total += 3;
        }
        temp--;
        number %= 100;
    }
    if(temp == 2) {
        if(get_length(number) == 1) {
            temp--;
        } else if(number < 20) {
            total += translation(number);
            temp -= 2;
        } else {
            total += translation((number / 10) * 10); //remove following number, and put 0
            number %= 10;
            temp--;
        }
    }
    if(temp == 1) {
        total += translation(number);
    }
    return total;
}

int main(void) {
    int sum = 0;
    for(int i = 1; i <= NUMBERS; i++) {
        int y = write_number(i, x);
        sum += y;
    }

    printf("%d\n", sum);

    return 0;
}

/*
 *  This is a copy of 17, where it doesn't translate, but just assigns values and returns the numbers
 */