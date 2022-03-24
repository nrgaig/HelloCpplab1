/****************************************************
  Created by Maor Frost 206370231 and Itay Oren 318648482
  cpp lab - Meir Litman
  exercise 4

****************************************************/

#include "Clock.h"

Clock::Clock(int _hour, int _minute, int _second) { // constructor

    if (_second < 0) { // if negative, throw problem.
        throw "Invalid time - negative number of seconds.\n";
    }
    if (_second > 60) { // if more than 60, throw problem.
        throw "Invalid time - more than 60 seconds.\n";
    }
    if (_minute < 0) { // if negative, throw problem.
        throw "Invalid time - negative number of minutes.\n";
    }
    if (_minute > 60) { // if more than 60, throw problem.
        throw "Invalid time - more than 60 minutes.\n";
    }
    if (_hour < 0) { // if negative, throw problem.
        throw "Invalid time - negative number of hours.\n";
    }
    if (_hour > 24) { // if more than 24, throw problem.
        throw "Invalid time - more than 24 hours.\n";
    }
    // if there are no problems, set the values.
    hour = _hour;
    minute = _minute;
    second = _second;


}

void Clock::setHour(int _hour) { // hours setter
    if (_hour < 0) {
        throw "Invalid time - negative number of hours.\n";
    }
    if (_hour > 24) {
        throw "Invalid time - more than 24 hours.\n";
    }
    hour = _hour;
}

void Clock::setMinute(int _minute) { // minutes setter
    if (_minute < 0) {
        throw "Invalid time - negative number of minutes.\n";
    }
    if (_minute > 60) {
        throw "Invalid time - more than 60 minutes.\n";
    }
    minute = _minute;
}

void Clock::setSecond(int _second) { // seconds setter
    if (_second < 0) {
        throw "Invalid time - negative number of seconds.\n";
    }
    if (_second > 60) {
        throw "Invalid time - more than 60 seconds.\n";
    }
    second = _second;
}

int Clock::getHour() const {
    return hour;
}

int Clock::getMinute() const {
    return minute;
}

int Clock::getSecond() const {
    return second;
}


Clock Clock::operator+=(int secondToAdd) { // += operator, add some seconds to the current time.
    second += secondToAdd; // add the seconds to the current time
    if (second > 60) { // if the seconds are greater than 60, need to add minute.
        minute += 1; // add minute
        second = second - 60; // save the remains in second.
        if (minute > 60) { // if the minutes are greater than 60, need to add hour.
            hour += 1; // add hour
            minute = minute - 60; // save the remains in minute.
            if (hour > 24) { // if the hours are greater than 24, need to move to the next day.
                hour = 0;
            }
        }
    }
    return *this;
}

ostream &operator<<(ostream &os, const Clock &ms) { // ostream operator
    /*  if the value is smaller than 10  print 0 before printing it
        because we need to print in hh:mm:ss format */
    (ms.hour < 10) ? os << '0' << ms.hour << ':' : os << ms.hour << ':';
    (ms.minute < 10) ? os << '0' << ms.minute << ':' : os << ms.minute << ':';
    (ms.second < 10) ? os << '0' << ms.second : os << ms.second;
    return os;
}

istream &operator>>(istream &is, Clock &ms) { // istream operator
    int _hour, _second, _minute; // temporary variables
    is >> _hour >> _minute >> _second;  // get values from steam

    /* set the values */
    ms.setHour(_hour);
    ms.setMinute(_minute);
    ms.setSecond(_second);

//    if (_second < 0) {
//        throw "Invalid time - negative number of seconds.\n";
//    }
//    if (_second > 60) {
//        throw "Invalid time - more than 60 seconds.\n";
//    }
//    if (_minute < 0) {
//        throw "Invalid time - negative number of minutes.\n";
//    }
//    if (_minute > 60) {
//        throw "Invalid time - more than 60 minutes.\n";
//    }
//    if (_hour < 0) {
//        throw "Invalid time - negative number of hours.\n";
//    }
//    if (_hour > 24) {
//        throw "Invalid time - more than 24 hours.\n";
//    }
//    ms.hour = _hour;
//    ms.minute = _minute;
//    ms.second = _second;

    return is;
}