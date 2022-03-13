/****************************************************
  Created by Maor Frost 206370231 and Itay Oren 318648482
  cpp lab - Meir Litman
  exercise 3 task 2
****************************************************/
#include <iostream>
#include "MyDate.h"

using namespace std;

MyDate::MyDate(int _day, int _month, int _year) {
    this->check(_day, _month, _year); // TODO
}

MyDate::MyDate(const MyDate &copy) {
    day = copy.day;
    month = copy.month;
    year = copy.year;
}

void MyDate::setDate(int _day, int _month, int _year) {
    this->check(_day, _month, _year);
}

void MyDate::check(int _day, int _month, int _year) {
    if (_day < 1 || _day > 30) {
        cout << "Error day" << endl;
        day = 1;
    } else day = _day;
    if (_month < 1 || _month > 12) {
        cout << "Error month" << endl;
        month = 1;
    } else month = _month;
    if (_year < 1920) {
        cout << "Error year" << endl;
        year = 1920;
    } else year = _year;
}

void MyDate::print() {
    cout << day << '/' << month << '/' << year;
}

MyDate MyDate::operator=(const MyDate &rhs) {
    day = rhs.day;
    month = rhs.month;
    year = rhs.year;
}

MyDate MyDate::operator++(int trash) {
    MyDate temp = *this;
    if (day == 30) {
        if (month == 12) {
            day = 1;
            month = 1;
            year += 1;
        } else {
            day = 1;
            month += 1;
        }
    } else { day += 1; }
    return temp;
}

MyDate &MyDate::operator++() {
    if (day == 30) {
        if (month == 12) {
            day = 1;
            month = 1;
            year += 1;
        } else {
            day = 1;
            month += 1;
        }
    } else { day += 1; }
    return *this;
}

bool MyDate::operator==(const MyDate &rhs) const {
    return day == rhs.day &&
           month == rhs.month &&
           year == rhs.year;
}

bool MyDate::operator!=(const MyDate &rhs) const {
    return !(rhs == *this);
}

bool MyDate::operator<(const MyDate &rhs) const {
    if (year < rhs.year)
        return true;
    if (year > rhs.year)
        return false;
    if (month < rhs.month)
        return true;
    if (month > rhs.month)
        return false;
    if (day < rhs.day)
        return true;
    else
        return false;
}

bool MyDate::operator>(const MyDate &rhs) const {
    return rhs < *this;
}

bool MyDate::operator<=(const MyDate &rhs) const {
    return !(rhs < *this);
}

bool MyDate::operator>=(const MyDate &rhs) const {
    return !(*this < rhs);
}


