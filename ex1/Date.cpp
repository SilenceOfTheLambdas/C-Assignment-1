#include <iostream>
#include "Date.h"

using namespace std;

Date::Date() {
    this->d = 1;
    this->m = 1;
    this->y = 1999;
}

Date::Date(unsigned int d,unsigned int m,unsigned int y) {

    this->d = d;
    this->m = m;
    this->y = y;

    int maxDays;

    switch(m) {
        case (1 || 3 || 5 || 7 || 8 || 10 || 12):
            maxDays = 31;
            break;
        case 2:
            if (Date::isLeapYear()) {
                maxDays = 29;
            } else {
                maxDays = 28;
            }
            break;
        default:
            maxDays = 30;
            break;

    }

    // Error checking for input of date
    if (d < 1 || d > maxDays) 
        cout << "Please enter a valid day!" << endl;
        d = 1; m = 1; y = 1999;
    if (m < 1 || m > 12) 
        cout << "Please enter a valid month!" << endl;
        d = 1; m = 1; y = 1999;
    if (y < 1000) 
        cout << "Please use a valid year!" << endl;
        d = 1; m = 1; y = 1999;
}