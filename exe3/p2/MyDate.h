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
    MyDate(int _day = 1, int _month = 1, int _year = 1920);

    MyDate(const MyDate &copy);

    void setDate(int _day, int _month, int _year);

    void operator++(int trash); // ++i

    void operator++(); // i++

    void operator=(const MyDate &copy);

    bool operator>(const MyDate &copy);

    bool operator<(const MyDate &copy);

    bool operator==(const MyDate &copy);

    void print();
};


#endif //HELLOCPPLAB1_MYDATE_H
