#include <iostream>
#include "Date.h"
#include "Age.h"
using namespace std;

int main() {
    //Age tests :
    //+--------------------------------------------------+
    Age noArg;
    Age age(22 , 1 , 19);
    Age copyC = age;
    cout<<"noArg Print : ";
    noArg.printAge();
    cout<<"getMethod test : "<<age.getDay()<<" "<<age.getMonth()<<" "<<age.getYear()<<endl;
    cout<<"CopyConstructor test : ";
    copyC.printAge();
    noArg.setDay(3);
    noArg.setMonth(5);
    noArg.setYear(23);
    cout<<"noArg after set : ";
    noArg.printAge();
    Age temp;
    temp = Age::convertDayToAge(558);
    cout<<"convertDayToAge test : ";
    temp.printAge();
    //-+++++++++++++++++++++++++++++++++++++++++++++++++++-
    //Age tests ends here

    //Date tests :
    //+---------------------------------------------------+

    Date today(23, 2, 1400);
    Date tmp;
    Date birthDate(1 , 1 ,1381);
    temp = today.calculateAge(birthDate);
    cout<<"calculateAge function test : ";
    temp.printAge();
    tmp = today.nYearBefore(20);
    cout<<"nYearBefore func test : "<<tmp.toString();
    tmp = today.nMonthBefore(123);
    cout<<"nMonth func test : "<<tmp.toString();
    tmp = today.nDayBefore(656);
    cout<<"nDayBefore func test : "<<tmp.toString();
    tmp = today.birthDate(age);
    cout<<"birthDate func test : "<<tmp.toString();
    tmp = today.nYearAfter(23);
    cout<<"nYearAfter func test : "<<tmp.toString();
    tmp = today.nMonthAfter(123);
    cout<<"nMonthAfter func test : "<<tmp.toString();
    tmp = today.nDayAfter(758);
    cout<<"nDayAfter func test : "<<tmp.toString();
    int dist = today.distanceDates(birthDate);
    cout<<"distanceDate test : "<<dist;

    //-+++++++++++++++++++++++++++++++++++++++++++++++++++-
    //Date tests ends here


    return 0;
}
