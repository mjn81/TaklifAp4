#include "Date.h"

Date::Date(int day, int month, int year) {
    this->day = new int{day};
    this->month = new int{month};
    this->year = new int{year};
}

Date::Date(Date &date) {
    day = date.day;
    month = date.month;
    year = date.year;
}

Date::~Date() {
    delete day;
    delete month;
    delete year;
}

int Date::getDay() {
    return *day;
}

int Date::getMonth() {
    return *month;
}

int Date::getYear() {
    return *year;
}

void Date::setDay(int Day) {
    *day = Day;
}

void Date::setMonth(int Month) {
    *month = Month;
}

void Date::setYear(int Year) {
    *year = Year;
}

string Date::toString() {
    return to_string(*year) + " / " + to_string(*month) + " / " + to_string(*day);
}

Age Date::calculateAge(Date &date) {
    int y, m, d;
    y = *year - date.getYear();
    m = *month - date.getMonth();
    d = *day - date.getDay();
    Age res(d, m, y);
    return res;
}

Date Date::nYearBefore(int n) {
    int y = *year - n;
    int d = *day;
    int m = *month;
    Date temp(d , m , y);
    return temp;
}

Date Date::nMonthBefore(int n) {
    int y = *year - n/12;
    n %=12;
    int m = *month - n;
    int d = *day;
    Date temp(y , m , d);
    return temp;
}

Date Date::nDayBefore(int n) {
    int y = *year - n/360;
    n %=360;
    int m = *month - n/30;
    n %=30;
    int d = *day - n;
    Date temp(y, m, d);
    return temp;
}

