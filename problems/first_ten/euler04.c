#include <stdio.h>

int greatest_palindrome(int n);
int is_palindrome(int n);

int main() {
    int x = greatest_palindrome(999);
    printf("%d \n", x);
    return 0;
}

int greatest_palindrome(int n) {
    int biggest = 0;   
    for(int i = n ;i > 9; i--) {
        for(int  j = n; j > 9; j--) {
            int x = i * j;
            if(is_palindrome(x) && x > biggest)
                biggest = x;
        }
    }
    return biggest;
}

int is_palindrome(int n) {
    int x = n;
    int y = 0;
    while(x != 0) {
        y *= 10;
        y = (y + ( x % 10 ));
        x = x / 10;
    }
    if( y == n)
        return 1;
    else return 0;
}
