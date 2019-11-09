/**
 * Author: Callum-James Smith
 * Date Created: 04-11-2019
 * Last Updated: 09-11-2019
 */
#include <iostream>
#include "Date.h"

using namespace std;

int main() {
    // Testing
	Date(12, 6, 2100);
    system("pause");
}

Date::Date() {
    this->d = 1;
    this->m = 1;
    this->y = 1999;
}

Date::Date(unsigned int d,unsigned int m,unsigned int y) {

    this->d = d;
    this->m = m;
    this->y = y;

    int maxDays; // Stores the maximum number of days in that month

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
        cout << "Please enter a valid year!" << endl;
        d = 1; m = 1; y = 1999;
}

bool Date::isLeapYear() const {
    // This will return true fi the year given is a leap year,
    // False, if not a leap year
    if (y % 4 == 0) {
        if (y % 100 == 0) {
            if (y % 400 == 0)
                return true;
            else return false;
        } else return true;
    } else return false;
}

// Implement operator functions
Date& Date::operator++() {
// Overloading of ++ operator, this function will return a new value.
// This value being; the Date increased by 1.
    int maxDays; // Stores the maximum number of days in that month

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

    if (d == maxDays) {
        d = 01;
        if (m == 12) {
            m = 01;
            y += 1;
        } else m += 1;
    } else {
        d += 1;
    }

    return *this;
}

Date& Date::operator--() {
// Overloading of -- operator, this function will return a new value.
// This value being; the Date decreased by 1.
    int maxDays; // Stores the maximum number of days in that month

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

    if (d == 1) {
        d = maxDays;
        if (m == 1) {
            y -= 1;
        } else m -= 1;
    } else {
        d -= 1;
    }

    return *this;
}