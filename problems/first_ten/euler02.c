#include <stdio.h>

#define swap(x,y) 

int main() {
    
    int x = 0;
    int y = 1;
    int sum = 0;
    //  0 1 x -> 0 1 0 -> 1 1 0 -> 1 1 -> 1 1 1 -> 1 1 1 -> 1 2 -> 
    while(x < 4000000) {
        int _temp = y;
        y = x;
        x += _temp;
        
        if(x % 2 == 0)
            sum += x;
    }
    printf("%d\n", sum);
    return 0;
}
