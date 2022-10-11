#ifndef _Date_H_
#define _Date_H_

// Self created date type for use only in this project
typedef struct Date {
    unsigned short Day;
    unsigned short Month;
    unsigned short Year;
    enum {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday} Week_Day;
} Date;

const Date MIN_DATE = {01, 01, 1900, Sunday};

char* SDate(Date date) {

    return "";
}
#endif