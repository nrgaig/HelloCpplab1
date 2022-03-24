/****************************************************
  Created by Maor Frost 206370231 and Itay Oren 318648482
  cpp lab - Meir Litman
  exercise 4
  class header implement clock/time
****************************************************/

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
    Clock& operator= (const Clock& copy);


    friend ostream& operator<<(ostream& os, const Clock& ms); // ostream operator
    friend istream& operator>>(istream& is, Clock& ms);// istream operator


private:
    //**i think they mean to initialize in this section, check it - (maor)
    int hour;//=0
    int minute;//=0
    int second;//=0
};


#endif //HELLOCPPLAB1_CLOCK_H
