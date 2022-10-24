#include "Date.h"
#include <stdio.h>

int main() {
//    Date myDate = MIN_DATE;
    Date myDate = MIN_DATE;
    Date xDate = {01, 01, 0001};
    printf("%s\n", SDate(myDate));

    Add_Days(&myDate, -1000);

    printf("%s\n", SDate(myDate));
    int days = day_diff(myDate, xDate);
    printf("%d\n", days);
    return 0;
}

