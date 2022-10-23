#include <stdio.h>
#include <stdlib.h>
#include "Date.h"

// Self created date type for use only in this project
const Date MIN_DATE = {01, 01, 1900, Sunday};
const int Month_Days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

void Month_Carry(Date *date);
void Month_Negative(Date *date);

char* SDate(Date date) {
    char *day = malloc(1);
    sprintf(day, "%d/%d/%d", date.Day, date.Month, date.Year);
    return day;
}

void Add_Days(Date *date, int days) {
    date->Day += days;
    
}

void Add_Months(Date *date, int months) {
    date->Month += months;
    if(date->Month > 12) {
        Month_Carry(date);
    }
    if(date->Month < 1) {
        Month_Negative(date);
    }
}

void Add_Years(Date *date, int years) {
    date->Year += years;
}

int is_leap_year(Date date) {
    int year = date.Year;
    if(year % 100 == 0 && year % 400 != 0) {
        return 0;
    }
    if(year % 4 != 0) {
        return 0;
    }
    return 1;
}

void Month_Carry(Date *date) {
    while(date->Month > 11) {
        date->Year++;
        date->Month -=12;
    }
}

void Month_Negative(Date *date) {
    while(date->Month < 1) {
        date->Year--;
        date->Month += 12;
    }
}
