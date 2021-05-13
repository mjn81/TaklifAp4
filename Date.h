#ifndef TAKLIF4AP_DATE_H
#define TAKLIF4AP_DATE_H

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

    int getDay();

    int getMonth();

    int getYear();

    void setDay(int);

    void setMonth(int);

    void setYear(int);

    string toString();

    Age calculateAge(Date &);

    Date nYearBefore(int);

    Date nMonthBefore(int);

    Date nDayBefore(int);
};


#endif
