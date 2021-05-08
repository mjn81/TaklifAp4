#ifndef TAKLIF4AP_AGE_H
#define TAKLIF4AP_AGE_H


class Age {
private:
    int day, month, year;
public:
    Age() : day(0), month(0), year(0) {}

    Age(int day, int month, int year);

    Age(Age &);

    int getDay() const;

    int getMonth() const;

    int getYear() const;

    void setDay(int);

    void setMonth(int);

    void setYear(int);

    void printAge() const;

    Age convertDayToAge(int);

};


#endif
