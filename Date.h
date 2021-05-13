#ifndef TAKLIF4AP_DATE_H
#define TAKLIF4AP_DATE_H
#include <iostream>
#include <string>
#include "Age.h"
using namespace std;

class Date {

private:
    int *day{}, *month{}, *year{};
public:
    Date() : day(new int{}), month(new int{}), year(new int{}) {}

    Date(int, int, int);

    Date(Date &);

    ~Date();

    int getDay() const;

    int getMonth() const;

    int getYear() const;

    void setDay(int);

    void setMonth(int);

    void setYear(int);

    string toString();

    Age calculateAge(Date &);

    Date nYearBefore(int , int nm=-1, int nd=-1);

    Date nMonthBefore(int ,int nd=-1);

    Date nDayBefore(int);

    Date birthDate(Age);

    Date nYearAfter(int);

    Date nMonthAfter(int);

    Date nDayAfter(int);

    int distanceDates(Date);

};


#endif
