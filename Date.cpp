#include "Date.h"

Date::Date(int day, int month, int year) {
    if (day < 0 || day > 30 || month < 0 || month > 12 || year < 0) {
        std::cout << "invalid input!";
        exit(-1);
    }
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

int Date::getDay() const {
    return *day;
}

int Date::getMonth() const {
    return *month;
}

int Date::getYear() const {
    return *year;
}

void Date::setDay(int Day) {
    if (Day <= 0 || Day > 30) {
        std::cout << "invalid input!";
        exit(-1);
    }
    *day = Day;
}

void Date::setMonth(int Month) {
    if (Month <= 0 || Month > 12) {
        std::cout << "invalid input!";
        exit(-1);
    }
    *month = Month;
}

void Date::setYear(int Year) {
    if (Year <= 0) {
        std::cout << "invalid input!";
        exit(-1);
    }
    *year = Year;
}

string Date::toString() {
    return to_string(*year) + " / " + to_string(*month) + " / " + to_string(*day) + "\n";
}

Age Date::calculateAge(Date &date) {
    int y, m, d;
    y = *year - date.getYear();
    m = *month - date.getMonth();
    d = *day - date.getDay();
    Age res(d, m, y);
    return res;
}

Date Date::nYearBefore(int n, int nm, int nd) {
    int y = *year - n;
    if (y <= 0 || n < 0) {
        cout << "Invalid input!!";
        exit(-1);
    }
    int d = *day;
    int m = *month;
    if (nm > 0) {
        m = nm;
    }
    if (nd > 0) {
        d = nd;
    }
    Date temp(d, m, y);
    return temp;
}

Date Date::nMonthBefore(int n, int nd) {
    if (n < 0) {
        cout << "Invalid input!!";
        exit(-1);
    }
    int ny = n / 12;
    n %= 12;
    int m = *month - n;
    if (m <= 0) {
        ny++;
        m += 12;
    }
    int d = *day;
    if (nd > 0)
        d = nd;
    Date temp;
    temp = nYearBefore(ny, m, d);
    return temp;
}

Date Date::nDayBefore(int n) {
    if (n < 0) {
        cout << "Invalid input!!";
        exit(-1);
    }
    int nm = n / 30;
    n %= 30;
    int d = *day - n;
    if (d <= 0) {
        nm++;
        d += 30;
    }
    Date temp;
    temp = nMonthBefore(nm, d);
    return temp;
}

Date Date::birthDate(Age myAge) {
    int n = myAge.getDay() + myAge.getMonth() * 30 + myAge.getYear() * 360;
    Date temp;
    temp = nDayBefore(n);
    return temp;
}

Date Date::nYearAfter(int n) {
    if (n < 0) {
        cout << "Invalid input!!";
        exit(-1);
    }
    int y = *year + n;
    int m = *month;
    int d = *day;
    Date temp(d, m, y);
    return temp;
}

Date Date::nMonthAfter(int n) {
    if (n < 0) {
        cout << "Invalid input!!";
        exit(-1);
    }
    int y = *year + n / 12;
    n %= 12;
    int m = *month + n;
    int d = *day;
    Date temp(d, m, y);
    return temp;

}

Date Date::nDayAfter(int n) {
    if (n < 0) {
        cout << "Invalid input!!";
        exit(-1);
    }
    int y = *year + n / 360;
    n %= 360;
    int m = *month + n / 30;
    n %= 30;
    int d = *day + n;
    Date temp(d, m, y);
    return temp;
}

int Date::distanceDates(Date date) {
    unsigned int res = (*year - date.getYear()) * 360 + (*month - date.getMonth()) * 30 + (*day - date.getDay());
    return res;
}
