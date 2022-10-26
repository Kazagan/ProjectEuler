#include "Date.h"
#include <stdio.h>

int main() {
    Date myDate = {6, 1, 1901, Sunday};
    printf("%s\n", SDate(myDate));
    int count = 0;
    while(myDate.Year < 2001) {
        if(myDate.Day == 1) {
            count++;
            printf("%s\n", SDate(myDate));
        }
        Add_Days(&myDate, 7);
    }
    printf("%d\n", count);
    return 0;
}