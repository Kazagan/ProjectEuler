#include "Date.h"
#include <stdio.h>

int main() {
//    Date myDate = MIN_DATE;
    Date myDate = {01, 01, 1904};
    printf("%s\n", SDate(myDate));

    Add_Days(&myDate, -1000);

    printf("%s\n", SDate(myDate));
    Date testDate = {1, 1, 1900, Sunday};
    return 0;
}

