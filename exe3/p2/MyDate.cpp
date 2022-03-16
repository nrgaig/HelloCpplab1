/****************************************************
  Created by Maor Frost 206370231 and Itay Oren 318648482
  cpp lab - Meir Litman
  exercise 3 task 2
  class representing date to understand some operators
****************************************************/
#include <iostream>
#include "MyDate.h"

using namespace std;

MyDate::MyDate(int _day, int _month, int _year) {// constructor
    if (_day < 1 || _day > 30) { // checking if day value is invalid. otherwise, it set it.
        cout << "Error day" << endl;
        day = 1;
    } else day = _day;
    if (_month < 1 || _month > 12) {// checking if month value is invalid. otherwise, it set it.
        cout << "Error month" << endl;
        month = 1;
    } else month = _month;
    if (_year < 1920) {// checking if year value is invalid. otherwise, it set it.
        cout << "Error year" << endl;
        year = 1920;
    } else year = _year;
}

MyDate::MyDate(const MyDate &copy) {// copy constructor
    day = copy.day;
    month = copy.month;
    year = copy.year;
}

void MyDate::setDate(int _day, int _month, int _year) { // update properties' values to new values.
    if (!(_day < 1 || _day > 30 || _month < 1 || _month > 12 ||
          _year < 1920)) { // checking if day value is invalid. otherwise, it set it.
        day = _day;
        month = _month;
        year = _year;
    }
}

void MyDate::print() const { // printing date in format dd/mm/yy
    cout << day << '/' << month << '/' << year;
}

MyDate &MyDate::operator=(const MyDate &rhs) {// Assigning operator - coping values from 'rhs' to 'this'.
    day = rhs.day;      //copy day value
    month = rhs.month;  //copy month value
    year = rhs.year;    //copy year value
    return *this;
}

MyDate MyDate::operator++(int trash) {  //(postfix)
    // i++ (increase date by 1 - postfix)
    MyDate tmp = *this;  // creating new MyDate duplication
    if (++day > 30) {// if adding 1 to day value is not in bound, day is the 1st and increase month value
        day = 1;
        if (++month > 12) { // if adding 1 to mount value is not in bound, month is 1 and increase year value
            month = 1;
            year++;
        }
    }
    return tmp;
}

MyDate &MyDate::operator++() {// ++i (increase date by 1 - prefix)
    if (++day > 30) {// if adding 1 to day value is not in bound, day is the 1st and increase month value
        day = 1;
        if (++month > 12) { // if adding 1 to mount value is not in bound, month is 1 and increase year value
            month = 1;
            year++;
        }
    }
    return *this;
}

bool MyDate::operator==(const MyDate &rhs) const { // check if ths is same date like 'this'
    return day == rhs.day &&
           month == rhs.month &&
           year == rhs.year; // comparing each value of each property of both this and rhs.
}

bool MyDate::operator!=(const MyDate &rhs) const {// check if ths is NOT same date like 'this'
    return !(rhs == *this);
}

bool MyDate::operator<(const MyDate &rhs) const {// comparing each value of each property of both this and rhs.
    if (year < rhs.year)
        return true;
    if (year > rhs.year)
        return false;
    if (month < rhs.month)
        return true;
    if (month > rhs.month)
        return false;
    return day < rhs.day;
}

bool MyDate::operator>(const MyDate &rhs) const {// comparing each value of each property of both this and rhs.
    return rhs < *this;
    if (day > rhs.day)          // if  this->day   moreThan rhs.day
        if (month >= rhs.month) // AND this->month moreThan/equal to rhs.month
            if (year >= rhs.year)// AND this->year  moreThan/equal to rhs.year
                return true;
    // else if rhs.day moreThan/equal this->day
    if (month > rhs.month)// AND this->month moreThan rhs.month
        return true;
// else if rhs' day and month moreThan/equal this->day
    return year > rhs.year;//if this->year moreThan rhs.year return true else false
}

bool MyDate::operator<=(const MyDate &rhs) const {
    return !(rhs < *this);
}

bool MyDate::operator>=(const MyDate &rhs) const {
    return !(*this < rhs);
}



