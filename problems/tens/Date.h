struct date {
  int Day;
  int Month;
  int Year;
  enum {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday} Week_Day;
};

typedef struct date Date;
extern const Date MIN_DATE;
char* SDate(Date date);
void Add_Days(Date *date, int days);
void Add_Months(Date *date, int months);
void Add_Years(Date *date, int years);
int is_leap_year(int year);
int day_diff(Date first, Date second);
int total_days(Date *date);