#include <stdio.h>

#define increment += 2520

int main() {
    int checks[] = { 3, 4, 5, 7, 8, 9, 11, 13, 16, 17, 19 };
    int count =  sizeof(checks) / sizeof(int);
    int is_found = 1;
    long n = 2520;
    while(is_found) {
        n increment;
        for(int i = 0; i < count; i++) {
            if(n % checks[i] != 0)
                break;
            if(checks[i] == 19)
                is_found = 0;
        }
    }
    printf("%ld\n", n);
    return 0;
}
