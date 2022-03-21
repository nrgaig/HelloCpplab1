//
// Created by itayo on 20/03/2022.
//

#ifndef HELLOCPPLAB1_CLOCK_H
#define HELLOCPPLAB1_CLOCK_H
#include <iostream>
using namespace std;


class Clock {
public:
    Clock(int _hour = 0, int _minute = 0, int _second = 0); // constructor

    int getHour() const;

    int getMinute() const;

    int getSecond() const;

    void setHour(int _hour);

    void setMinute(int _minute);

    void setSecond(int _second);

    Clock operator+=(int _minuteToAdd);


    friend ostream& operator<<(ostream& os, const Clock& ms); // ostream operator
    friend istream& operator>>(istream& is, Clock& ms);// istream operator


private:
    int hour;
    int minute;
    int second;
};


#endif //HELLOCPPLAB1_CLOCK_H
