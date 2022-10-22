#include <stdio.h>
#include <stdlib.h>
#include "Date.h"

// Self created date type for use only in this project

const Date MIN_DATE = {01, 01, 1900, Sunday};
char* SDate(Date date) {
    char *day = malloc(1);
    sprintf(day, "%d/%d/%d", date.Day, date.Month, date.Year);
    return day;
}

Date Add_Day(Date* date, int days) {
    date->Day += days;
}

