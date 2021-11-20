#include <stdio.h>
#include <stdlib.h>

#define RANDOM_DIGITS "9483748593"
#define LENGTH 10

int main() {
    int test[5][5];
    int count = 0;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            test[i][j] = ++count;
        }
    }
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%d: ", test[i][j]);
        }
        printf("\n");
    }
    return 0;
}

