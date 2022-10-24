#include <stdio.h>
#include <stdlib.h>
#include "Date.h"

// Self created date type for use only in this project
const Date MIN_DATE = {01, 01, 1900, Sunday};
const int Month_Days[12] = {
    31, // Jan
    28, // Feb
    31, // March
    30, // April
    31, // May
    30, // June
    31, // July
    31, // August
    30, // September
    31, // October
    30, // November
    31  // December
    };

void month_positive(Date *date);
void month_negative(Date *date);
void days_positive(Date *date);
void days_negative(Date *date);
int get_days_in_month(Date *date);

char* SDate(Date date) {
    char *day = malloc(1);
    sprintf(day, "%d/%d/%d", date.Month, date.Day, date.Year);
    return day;
}

void Add_Days(Date *date, int days) {
    date->Day += days;
    if(days > 0) {
        days_positive(date);
    }
    else {
        days_negative(date);
    }
}

void Add_Months(Date *date, int months) {
    date->Month += months;
    if(date->Month > 12) {
        month_positive(date);
    }
    if(date->Month < 1) {
        month_negative(date);
    }
}

void Add_Years(Date *date, int years) {
    date->Year += years;
}

int is_leap_year(int year) {
    if(year % 100 == 0 && year % 400 != 0) {
        return 0;
    }
    if(year % 4 != 0) {
        return 0;
    }
    return 1;
}

void month_positive(Date *date) {
    while(date->Month > 11) {
        date->Year++;
        date->Month -=12;
    }
}

void month_negative(Date *date) {
    while(date->Month < 1) {
        date->Year--;
        date->Month += 12;
    }
}

int get_days_in_month(Date *date) {
    if(date->Month == 2 && is_leap_year(date->Year)) {
        return 29;
    }
    return Month_Days[date->Month -1];
}

void days_positive(Date *date) {
    int days_in_month = get_days_in_month(date);
    while(date->Day > days_in_month) {
        date->Day -= days_in_month;
        Add_Months(date, 1);
        days_in_month = get_days_in_month(date);
    }
}

void days_negative(Date *date) {
    while(date->Day <= 0) {
        Add_Months(date, -1);
        int days_in_month = get_days_in_month(date);
        date->Day += days_in_month;
    }
}

int day_diff(Date first, Date second) {
    return total_days(&first) - total_days(&second);
}

int total_days(Date *date) {
    int output = date->Day;
    int completed_months = date->Month - 1;
    while(completed_months > 0) {
        output += completed_months == 2 && is_leap_year(date->Year) ? 29 : Month_Days[completed_months - 1];
        completed_months--;
    }
    int year = date->Year;
    while(year > 0) {
        output += is_leap_year(year) ? 366 : 365;
        year--;
    }
    return output;
}