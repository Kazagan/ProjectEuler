#include <stdio.h>
#include <stdlib.h>
#include "Date.h"

// Self created date type for use only in this project
// Kind of gave up while looking into keeping track of the day of the week.
// If i were to redo this, I would probably define a date as a count of days since x date instead of storing
// all three values.
const Date MIN_DATE = {01, 01, 1900, Monday};
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
void set_week_day(Date *date, int days);
char* get_week_day(int weekday);
int get_days_in_month(Date *date);

char* SDate(Date date) {
    char *day = malloc(1);
    sprintf(day, "%d/%d/%d %s \n", date.Month, date.Day, date.Year, get_week_day(date.Week_Day));
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
    int days = 0;
    while(years > 0) {
        years--;
        days += is_leap_year(date->Year++) ? 366 : 365;
    }
    set_week_day(date, days);
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
        Add_Years(date, 1);
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

void set_week_day(Date *date, int days) {
  int weekday = days % 7;
  if(weekday > 0) {
    while(weekday > 0) {
      if(date->Week_Day == 6) {
        date->Week_Day = 0;
      } else {
        date->Week_Day++;
      }
      weekday--;
    }
  }

  while(weekday < 0) {
    if(date->Week_Day == 0) {
      date->Week_Day = 6;
    } else {
      date->Week_Day--;
    }
    weekday++;
  }
}

char* get_week_day(int weekday) {
    switch(weekday) {
      case 0:
        return "Monday";
      case 1:
        return "Tuesday";
      case 2:
        return "Wednesday";
      case 3:
        return "Thursday";
      case 4:
        return "Friday";
      case 5:
        return "Saturday";
      case 6:
        return "Sunday";
      default:
        return "";
    }
}