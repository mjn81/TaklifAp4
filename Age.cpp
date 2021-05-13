#include <iostream>
#include "Age.h"

Age::Age(int day, int month, int year) {
    if (day < 0 || day > 30 || month < 0 || month > 12 || year < 0) {
        std::cout << "invalid input!";
        exit(-1);
    }
    this->day = day;
    this->month = month;
    this->year = year;
}

Age::Age(Age &copy) {
    day = copy.day;
    month = copy.month;
    year = copy.month;
}

int Age::getDay() const {
    return day;
}

int Age::getMonth() const {
    return month;
}

int Age::getYear() const {
    return year;
}

void Age::setDay(int Day) {
    if (Day < 0 || Day > 30) {
        std::cout << "invalid input!";
        exit(-1);
    }
    day = Day;
}

void Age::setMonth(int Month) {
    if (Month < 0 || Month > 12) {
        std::cout << "invalid input!";
        exit(-1);
    }
    month = Month;
}

void Age::setYear(int Year) {
    if (Year < 0) {
        std::cout << "invalid input!";
        exit(-1);
    }
    year = Year;
}

void Age::printAge() const {
    std::cout << year << " years , " << month << " months , " << day << " days\n";
}

Age Age::convertDayToAge(int Day) {
    if (Day < 0) {
        std::cout << "invalid input!";
        exit(-1);
    }
    int y = Day / 360;
    Day %= 360;
    int m = Day / 30;
    Day %= 30;
    int d = Day;
    Age temp(d, m, y);
    return temp;
}