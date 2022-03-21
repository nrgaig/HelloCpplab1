//
// Created by itayo on 20/03/2022.
//

#include "Clock.h"

Clock::Clock(int _hour, int _minute, int _second) { // constructor
    if (_second < 0) {
        throw "Invalid time - negative number of seconds.\n";
    }
    if (_second > 60) {
        throw "Invalid time - more than 60 seconds.\n";
    }
    if (_minute < 0) {
        throw "Invalid time - negative number of minutes.\n";
    }
    if (_minute > 60) {
        throw "Invalid time - more than 60 minutes.\n";
    }
    if (_hour < 0) {
        throw "Invalid time - negative number of hours.\n";
    }
    if (_hour > 24) {
        throw "Invalid time - more than 24 hours.\n";
    }
    hour = _hour;
    minute = _minute;
    second = _second;


}

void Clock::setHour(int _hour) {
    if (_hour < 0) {
        throw "Invalid time - negative number of hours.\n";
    }
    if (_hour > 24) {
        throw "Invalid time - more than 24 hours.\n";
    }
    hour = _hour;
}

void Clock::setMinute(int _minute) {
    if (_minute < 0) {
        throw "Invalid time - negative number of minutes.\n";
    }
    if (_minute > 60) {
        throw "Invalid time - more than 60 minutes.\n";
    }
    minute = _minute;
}

void Clock::setSecond(int _second) {
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


Clock Clock::operator+=(int minuteToAdd) {
    minute += minuteToAdd;
    if (minute > 60) {
        second += 1;
        minute = minute - 60;
        if (second > 60) {
            hour += 1;
            second = second - 60;
            if (hour > 24) {
                throw "Invalid time - more than 24 hours.\n"; // TODO need this?
            }
        }
    }
    return *this;
}

ostream &operator<<(ostream &os, const Clock &ms) { // ostream operator
    (ms.hour < 10) ? os << '0' << ms.hour << ':' : os << ms.hour << ':';
    (ms.minute < 10) ? os << '0' << ms.minute << ':' : os << ms.minute << ':';
    (ms.second < 10) ? os << '0' << ms.second : os << ms.second;
    return os;
}

istream &operator>>(istream &is, Clock &ms) { // istream operator
    int _hour, _second, _minute;
    is >> _hour >> _minute >> _second;
    if (_second < 0) {
        throw "Invalid time - negative number of seconds.\n";
    }
    if (_second > 60) {
        throw "Invalid time - more than 60 seconds.\n";
    }
    if (_minute < 0) {
        throw "Invalid time - negative number of minutes.\n";
    }
    if (_minute > 60) {
        throw "Invalid time - more than 60 minutes.\n";
    }
    if (_hour < 0) {
        throw "Invalid time - negative number of hours.\n";
    }
    if (_hour > 24) {
        throw "Invalid time - more than 24 hours.\n";
    }
    ms.hour = _hour;
    ms.minute = _minute;
    ms.second = _second;

    return is;
}