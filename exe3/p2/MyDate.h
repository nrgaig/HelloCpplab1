/****************************************************
  Created by Maor Frost 206370231 and Itay Oren 318648482
  cpp lab - Meir Litman
  exercise 3 task 2
****************************************************/

#ifndef HELLOCPPLAB1_MYDATE_H
#define HELLOCPPLAB1_MYDATE_H


class MyDate {
private:
    int day;
    int month;
    int year;
public:
    explicit MyDate(int _day = 1, int _month = 1, int _year = 1920); // constructor

    MyDate(const MyDate &copy); // copy constructor

    void setDate(int _day, int _month, int _year); //

    MyDate& operator=(const MyDate &rhs);
    MyDate operator++(int trash);
    MyDate& operator++();

    bool operator<(const MyDate &rhs) const;

    bool operator>(const MyDate &rhs) const;

    bool operator<=(const MyDate &rhs) const;

    bool operator>=(const MyDate &rhs) const;

    bool operator==(const MyDate &rhs) const;

    bool operator!=(const MyDate &rhs) const;

    void print() const;

    void check(int _day, int _month, int _year);
};


#endif //HELLOCPPLAB1_MYDATE_H
