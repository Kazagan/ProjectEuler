#include <stdio.h>
#include <stdlib.h>

// Using while arry[i] != 0, as I know by the time it gets there the first values should not be zero
typedef struct amicable {
    int first;
    int second;
} Amicable;
int increase_array_size(int** arry, int size);
int *get_divisors(int n);
int sum_array(int *arry);
int contains(int *arry, int value);
Amicable check_amicable(int input);

int main() {
    
    /* int *divisors = get_divisors(284); */
    int size = 10;
    int *amicables = calloc(size, sizeof(int));
    int index = 0;
    fprintf(stdout, "before loop\n");
    for(int i = 1; i < 10000; i++) {
        if(contains(amicables, i) == 1) {
            continue;
        }

        Amicable result = check_amicable(i);
        if(result.first == 0) {
            continue;
        }
        printf("%d | %d\n", result.first, result.second);
        amicables[index++] = result.first;
        amicables[index++] = result.second;
    

        if((size - index) <= 2) {
            size = increase_array_size(&amicables, size);
        }
    }
    
    printf("%d\n", sum_array(amicables));
    return 0;
}

Amicable check_amicable(int input) {
    int *divisors = get_divisors(input);
    int possible_pair = sum_array(divisors);

    int *ppdivisors = get_divisors(possible_pair);
    int ppsum = sum_array(ppdivisors);
    if(ppsum == input && input != possible_pair) {
        Amicable result = {input, possible_pair};
        return result;
    }
    Amicable result = { 0, 0 };
    return result;
}

int *get_divisors(int n) {
    int size = 10;
    int *divisors = calloc(size, sizeof(int));
    divisors[0] = 1;
    int index = 1;
    int halfway = n / 2;
    for(int i = 2; i <= halfway; i++) {
        if(n % i == 0) {
            divisors[index++] = i;
        }
        if(size - index <= 2) {
            size = increase_array_size(&divisors, size);
        }
    }
    return divisors;
}

int contains(int *arry, int value) {
    int i = 0;
    while(arry[i] != 0) {
        if(arry[i++] == value) {
            return 1;
        }
    }
    return 0;
}

int sum_array(int *arry) {
    int sum = 0;
    int i = 0;
    while(arry[i] != 0) {
        sum += arry[i++];
    }
    return sum;
}

int increase_array_size(int** arry, int size) {
    int new_size = size * 2;
    int *old = arry[0];
    int *new  = realloc(old, new_size * sizeof(int));
    if(new == NULL) { 
        fprintf(stderr, "realloc failed to allocate memory"); 
        exit; 
    }
    arry[0] = new;
    return new_size;
}
