/****************************************************
  Created by Maor Frost 206370231 and Itay Oren 318648482
  cpp lab - Meir Litman
  exercise 3 task 2
  class header representing date to understand some operators
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

    void setDate(int _day, int _month, int _year); //set new date to current date update properties' values to new values.

    MyDate& operator=(const MyDate &rhs);// Assigning operator - coping values from 'rhs' to 'this'.
    MyDate operator++(int trash);// i++ (increase date by 1 - postfix)
    MyDate& operator++();// ++i (increase date by 1 - prefix)

    bool operator<(const MyDate &rhs) const;// comparing each value of each property of both this and rhs.

    bool operator>(const MyDate &rhs) const;// comparing each value of each property of both this and rhs.

    bool operator<=(const MyDate &rhs) const;

    bool operator>=(const MyDate &rhs) const;

    bool operator==(const MyDate &rhs) const;// check if ths is same date like 'this'

    bool operator!=(const MyDate &rhs) const;// check if ths is NOT same date like 'this'

    void print() const;// printing date in format dd/mm/yy
};


#endif //HELLOCPPLAB1_MYDATE_H
