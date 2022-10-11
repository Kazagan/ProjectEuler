#include "date.h"
#include <stdio.h>

int Main() {
    int x = 5;
    char* y = &x;

    printf("%d, %s \n", x, y);
}