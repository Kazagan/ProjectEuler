#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

#define SIZE 200
int increase_array(int **arry, int size);
int string_length(char* str);
long int to_int(char *input);
void print_array(int *arry, int length);

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
    
    //Starting size of array
    int size = 200; // Problem requires going to atleast 100! which is 158 characters.
    int *result = malloc(size * sizeof(int));
    
    printf("number: %ld length: %d\n", n, n_size);

    // insert initial number as start
    int j = size;
    for(int i = 0; i < n_size; i++ ) {
        result[j++ - n_size] = n_string[i] - '0';
    }
    print_array(result, size);    

    /* printf("%ld %d\n", n, n_size); */
    return 0;
}

void print_array(int *arry, int length) {
    for(int i = 0; i < length; i++) {
        printf("%d: %d ", i, arry[i]);
        if(i % 10 == 0) { printf("\n"); }
    }
    printf("\n");
}

int increase_array(int **myArray, int size) {
    int new_size = size * 2;
    int *x = myArray[0];
    int *new = realloc(x, new_size * sizeof(int));

    if(new == NULL) { exit; }
    x = new;
    myArray[0] = x;
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

*/
