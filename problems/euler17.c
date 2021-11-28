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

char* translation(int n) {
    switch(n) {
        case 1:
            return "One";
        case 2:
            return "Two";
        case 3:
            return "Three";
        case 4:
            return "Four";
        case 5:
            return "Five";
        case 6:
            return "Six";
        case 7:
            return "Seven";
        case 8:
            return "Eight";
        case 9:
            return "Nine";
        case 10:
            return "Ten";
        case 11:
            return "Eleven";
        case 12:
            return "Twelve";
        case 13:
            return "Thirteen";
        case 14:
            return "Fourteen";
        case 15:
            return "Fifteen";
        case 16:
            return "Sixteen";
        case 17:
            return "Seventeen";
        case 18:
            return "Eighteen";
        case 19:
            return "Nineteen";
        case 20:
            return "Twenty";
        case 30:
            return "Thirty";
        case 40:
            return "Forty";
        case 50:
            return "Fifty";
        case 60:
            return "Sixty";
        case 70:
            return "Seventy";
        case 80:
            return "Eighty";
        case 90:
            return "Ninety";
        default:
            return "";
    }
}

char *write_number(int n, int count) {
    char *output = malloc(sizeof(char) * MAX_SIZE);
    int temp = count;
    int number = n;
    if(temp == 4) {
        return "OneThousand";
    }
    if(temp == 3) {
        strcat(output, translation(number / 100));
        strcat(output, "Hundred");
        if(number % 100 != 0) {
            strcat(output, "And");
        }
        temp--;
        number %= 100;
    }
    if(temp == 2) {
        if(get_length(number) == 1) {
            strcat(output, "");
            temp--;
        } else if(number < 20) {
            strcat(output, translation(number));
            temp -= 2;
        } else {
            strcat(output, translation((number / 10) * 10)); //remove following number, and put 0
            number %= 10;
            temp--;
        }
    }
    if(temp == 1) {
        strcat(output, translation(number));
    }
    strcat(output, "\0");
    return output;
}

int main(void) {
    int sum = 0;
    for(int i = 1; i <= NUMBERS; i++) {
        int x = get_length(i);
        char *y = write_number(i, x);
        int length = strlen(y);
        sum += length;
//        printf("%d: %d %s %d\n", i, x, y, length);
    }

    printf("%d\n", sum);

    return 0;
}

/*
 *
 * So I need to be able to convert an int from 1-1000 into the string representation of it.
 * In the format of ThreeHundredAndFortyTwo
 * Where we count the AND as well.
 * So I need to be able to get the length of the int, to handle over 100, and 10000
 * After that I need to consider the best way to map numbers to their string version.
 * So 1 through 19, 20..30..40...90 need to be handled uniquely, as they are the main differences.
 * After 20, the numbers should be able to just concatenate the tens place and the ones, to make 23 = twentyThree
 *
 *
 */