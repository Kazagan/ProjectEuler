#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

#define sqr(x) ( (x) * (x) )

void die(char *message) {
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }
}

float pythagorean_triplet() {
    float a = 200.00f;
    float b = 301.00f;

    for(a = 200.00f; a < 300.00f; a++) {
        for(b = 301.00f; b < 500.00f; b++) {
            float c2 = sqr(a) + sqr(b);
            float c = sqrtf(c2);
            if(floorf(c) == c){ 
                printf("print(%f + %f + %f)\n", a, b, c);
                if(a + b + c == 1000.00f)
                    return a * b * c;
            }
        }
    }
    return 0.00f;
}

int main() {
    float x = pythagorean_triplet();
    if(x == 0.00f)
        printf("Not found");

    printf("%f\n", x);
    return 0;
}

/*
 
    A pathagreon triplet is where sqr(a) + sqr(b) = sqr(c) Where a, b and c are all perfect squares.
    Example is sqr(3) + sqr(4) = sqr(5) or 9 + 16 = 25.

    There exists exactly 1 where a + b + c = 1000. Find the product of the three numbers.
    ----------------------------------------------------------------------------------------   
    Could brute force it with a double loop, that would check every number for every number over 100 up to 500 (half of 1000)

    Instead I want to consider the rules of a triangle to figure out a better method for doing this.
    2 sides must be bigger than third, and hypotenuse will always be the largest..
    2 sides must be bigger than third, and hypotenuse will always be the largest.
    
    So while looping, we should consider the cap of a+b+c=1000, and a+b<c and c > a && b.
    We are starting the loop with a, so a < b < c.
    a + b should be greater than 501 to ensure that they are larger than c.
    a should be less than 1/3 of 1000.
    
    1000 / 3 ~= 333.333... if this is the average, we should consider that atleast one of a and b is less than this number
    Given that, then c must be equal to 333.333 + the sum of the difference of 333.333 and a and b.
    If 300 already exists as the smallest in a triplet over 1000, a is below 300.
    C should be less than 500, as a+b need to be greater than c.
    b should be less than 500 as the half way point.
    a should be larger than half the mean, 166, arbitraly picking 200 here.
  
    if a starts at 200, than a + b needs to be larger than the difference of a+b and 1000. So if we start at 200 for a, b must be at least 301.
    
    **First few attempts failed, because I was stopping b at 333, thinking it would be smaller than the mean. After further thought, I realized b should be allowed to go up to 500 as a greater bound. a should likely start at a smaller bound logically, but 200 ended up being the number for a so I didn't change it.
*/
