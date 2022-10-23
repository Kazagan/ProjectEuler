#include "Date.h"
#include <stdio.h>

int main() {
    Date myDate = MIN_DATE;
    printf("%s\n", SDate(myDate));

    Add_Days(&myDate, 2);
//    Add_Months(&myDate, 34);
//    Add_Years(&myDate, 2);
    printf("%s\n", SDate(myDate));

    Date testDate = {1, 1, 1900, Sunday};
    return 0;
}

