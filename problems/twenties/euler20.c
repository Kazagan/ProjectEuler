#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

#define SIZE 200
int increase_array(int **arry, int size);
int string_length(char* str);
long int to_int(char *input);
void print_array(int *arry, int length);
void print_number(int *array, int length);
int get_unused(int *array, int length);
int *initialize_array(int size, char *number, int number_length);
int *multiply_array(int *array, int size, long int multiplier);
int int_length(long int input);

void die(char *message) {
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }
    exit(-1);
}

int main(int argc, char** argv) {
    char *n_string = argv[1];
    int n_size = string_length(n_string);
    long int n = to_int(n_string);
    
    int size = SIZE; // Problem requires going to atleast 100! which is 158 characters.
    int *large_number = initialize_array(size, n_string, n_size);        
    
    while( n > 2) {
        large_number = multiply_array(large_number, size, --n);
        int unused = get_unused(large_number, size);
        if(unused < 50) {
            size = increase_array(&large_number, size);
        }
    }

    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += large_number[i];
    }
    print_number(large_number, size);
    printf("sum = %d\n", sum);
    return 0;
}

int *multiply_array(int *arry, int array_size, long int multiplier) {
    int multiplier_length = int_length(multiplier);
    int values[array_size][multiplier_length];
    for(int i = 0; i < array_size; i++) {
        for(int j = 0; j < multiplier_length; j++) {
            values[i][j] = 0;
        }
    }
    int *output = malloc(array_size * sizeof(int));
    
    for(int column = 0; column < multiplier_length; column++) {
        int x = multiplier % 10;
        multiplier /= 10;
        for(int row = array_size - 1; row >= 0; row--) {
            values[row - column][column] = arry[row] * x;
        }

        int carry = 0;
        for(int row = array_size - 1; row >= 0; row--) {
            int value = values[row-column][column] + carry;
            carry = 0;
            if(value > 9) {
                carry = value / 10;
            }
            value %= 10;
            values[row-column][column] = value;
        }
    }
    
    int carry = 0;
    for(int row = array_size -1; row >= 0; row--) {
        int sum = 0;
        for(int column = 0; column < multiplier_length; column++) {
            sum += values[row][column];
        }
        sum += carry;
        carry = sum / 10;
        output[row] = sum % 10;
    }
    return output;
}

int* initialize_array(int size, char *number, int number_length) {
    int *output = malloc(size * sizeof(int));
    int j = size;
    for(int i = 0; i < number_length; i++ ) {
        output[j++ - number_length] = number[i] - '0';
    }
    return output;
}

int increase_array(int **my_array, int size) {
    int new_size = size * 2;
    int* old = my_array[0];
    int* new  = calloc(new_size, sizeof(int));
    
    for(int i = size; i < new_size; i++) {
        new[i] = old[i - size];
    }
    my_array[0] = new;
    return new_size;
}

int string_length(char* str) {
    int counter = 0;
    while(str[counter] != '\0') {
        counter++;
    }
    return counter;
}

long int to_int(char *input) {
    char *ptr;
    errno = 0;
    long int n;
    n = strtol(input, &ptr, 10);
    if(n == LONG_MIN && errno != 0) { die("Number to small"); }
    if(n == LONG_MAX && errno != 0) { die("Number to big"); }
    if(*ptr != '\0') { die("Input not a number"); }
    return n;
}

int int_length(long int input) {
    int length = 0;
    int run = 1;
    while(run = 1) {
        if(input % 10 == 0 && input / 10 == 0) {
            break;
        }
        length++;
        input /= 10;
    }
    return length;
}

void print_array(int *arry, int length) {
    for(int i = 0; i < length; i++) {
        printf("%d: %d ", i, arry[i]);
        if(i % 10 == 0) { printf("\n"); }
    }
    printf("\n");
}

void print_number(int *array, int length) {
    int ignore_zero = 1;
    for(int i = 0; i < length; i++) {
        if(array[i] == 0 && ignore_zero == 1) {
            continue;
        }
        ignore_zero = 0;
        printf("%d", array[i]);
    }
    printf("\n");
}

int get_unused(int *array, int length) {
    int unused = 0;
    for(int i = 0; i < length; i++) {
        if(array[i] == 0) { 
            unused++;
            continue;
        }
        break;
    }
    return unused;
}

// As C does not have the ability (by default) to store extremely large numbers, I'm going to attempt to create my own multiplication
// so in the past I did addition, by adding and moving the remainder over 1. This worked well, so I'm going to attempt to do the same here.

/* starting at the tail end of the array, put the first number in
   10
   multiply by 9

   10
    9
   90
    8
  720

  100
   99
   --
  900
 9000
 ----
 9900
   98
-----

0156
1560
1716
*/
