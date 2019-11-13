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
	Date date = Date(30, 4, 2014);
    cout << ++date;
    cout << date++;

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

    if (m == (1 || 3 || 5 || 7 || 8 || 10 || 12)){
        maxDays = 31;
    } else if (m == 2) {
        if (Date::isLeapYear()) {
            maxDays = 29;
        } else maxDays = 28;
    } else maxDays = 30;

    // Error checking for input of date
    if ((d < 1) || (d > maxDays)) {
        cout << "Please enter a valid day!" << endl;
        this->d = 1; this->m = 1; this->y = 1999;
    }
    if ((m < 1) || (m > 12)) {
        cout << "Please enter a valid month!" << endl;
        this->d = 1; this->m = 1; this->y = 1999;
    }
    if (y < 1000)  {
        cout << "Please enter a valid year!" << endl;
        this->d = 1; this->m = 1; this->y = 1999;
    }
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

    if (m == (1 || 3 || 5 || 7 || 8 || 10 || 12)){
        maxDays = 31;
    } else if (m == 2) {
        if (Date::isLeapYear()) {
            maxDays = 29;
        } else maxDays = 28;
    } else maxDays = 30;

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

// Implementation of postfix version of ++
Date Date::operator++(int i) {
    int maxDays; // Stores the maximum number of days in that month
    Date date = Date(d, m, y);

    if (m == (1 || 3 || 5 || 7 || 8 || 10 || 12)){
        maxDays = 31;
    } else if (m == 2) {
        if (Date::isLeapYear()) {
            maxDays = 29;
        } else maxDays = 28;
    } else maxDays = 30;

    if (d == maxDays) {
        d = 01;
        if (m == 12) {
            m = 01;
            y += 1;
        } else m += 1;
    } else {
        d += 1;
    }

    return date;
}



Date& Date::operator--() {
// Overloading of -- operator, this function will return a new value.
// This value being; the Date decreased by 1.

    int maxDays; // Stores the maximum number of days in that month

    if (m == (1 || 3 || 5 || 7 || 8 || 10 || 12)){
        maxDays = 31;
    } else if (m == 2) {
        if (Date::isLeapYear()) {
            maxDays = 29;
        } else maxDays = 28;
    } else maxDays = 30;

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

// Overloading of string() function
Date::operator string() const {
    string day = to_string(d);
    string month = to_string(m);
    string year = to_string(y);
    string end;

    if (1 || 21 || 31) {
        end = "st";
    } else if (2 || 22) {
        end = "nd";
    } else if (3 || 23) {
        end = "rd";
    } else {
        end = "th";
    }

    for (int i = 0; i < 12; i++) {
        year = months[m - 1];
    }

    cout << day + end << month << year << endl;


}

// Overloading of << operator
ostream& operator<<(ostream& o, const Date& d) {
    o << d.d << '/' << d.m << '/' << d.y << endl;
    return o;
}

// operator < implementing
bool Date::operator<(const Date& other) const {
    if (y < other.y) {
        return true;
    } else if (m < other.m) {
        return true;
    } else if (d < other.d) {
        return true;
    } else return false;
}

bool Date::operator==(const Date& other) const {
    if ((d == other.d) && (y == other.y) && (m == other.m)) {
        return true;
    } else return false;
}

bool operator<=(const Date& d1, const Date& d2) {
    if (d1 < d2 || d1 == d2) {
        return true;
    } else return false;
}

bool operator>(const Date& d1, const Date& d2) {
    if (!(d1 < d2)) {
        return true;
    } else return false;
}

bool operator!=(const Date& d1, const Date& d2) {
    if (!(d1 == d2)) {
        return true;
    } return false;
}

bool operator>=(const Date& d1, const Date& d2) {
    if ((d1 > d2) || (d1 == d2)) {
        return true;
    } else return false;
}