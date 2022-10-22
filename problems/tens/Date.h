struct date {
  int Day;
  int Month;
  int Year;
  enum {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday} Week_Day;
};

typedef struct date Date;
extern const Date MIN_DATE;
char* SDate(Date date);
void Add_Days(Date* date, int days);
