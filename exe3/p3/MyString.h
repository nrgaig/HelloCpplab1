/****************************************************
  Created by Maor Frost 206370231 and Itay Oren 318648482
  cpp lab - Meir Litman
  exercise 3 task 3
****************************************************/

#ifndef HELLOCPPLAB1_MYSTRING_H
#define HELLOCPPLAB1_MYSTRING_H

#include <iostream>
#include <string.h>
using namespace std;

class MyString {

    int len = 0; // length of string
    char* str; // old C-string

public:
    MyString() : str(nullptr), len(0) {} //explicit empty constructor
    MyString(const char* s); //constructor
    MyString(const MyString& ms); //copy constructor
    MyString(MyString&& ms); // move constructor
    ~MyString(); //destructor

    char *getStr() const;

    MyString& operator=(const MyString& ms); //assignment operator
    MyString& operator=(MyString&& ms); //move assignment operator
    char & operator[](int index) ; // index access operator
    MyString insert( int index, const char* _str ) ; // insert string into our string and return results

    MyString  operator+(const MyString& ms) const; // addition operator
    MyString  operator* (const int) const; // multiply operator

    bool operator==(const MyString& ms) const; // equality operator
    bool operator!=(const MyString &rhs) const; // not equal operator

    bool operator<(const MyString &rhs) const; // smaller operator
    bool operator>(const MyString &rhs) const; // grater operator
    bool operator<=(const MyString &rhs) const; // smaller or equal operator
    bool operator>=(const MyString &rhs) const; // grater or equal operator

    friend ostream& operator<<(ostream& os, const MyString& ms); // ostream operator
    friend istream& operator>>(istream& is, MyString& ms);// istream operator




};


#endif //HELLOCPPLAB1_MYSTRING_H
