/****************************************************
  Created by Maor Frost 206370231 and Itay Oren 318648482
  cpp lab - Meir Litman
  exercise 3 task 3
****************************************************/
#include <cstring>
#include "MyString.h"

MyString::MyString(const char *s) {//constructor
    if (s)
    {
        len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
    } else
        str = nullptr;

}

MyString::MyString(const MyString &ms)//copy constructor
        : MyString(ms.str) {
 }

MyString::MyString(MyString &&ms) {  // move constructor

    len = ms.len;
    str = ms.str; // steal (dont copy) rvalue's data
    ms.str = nullptr; //very important!!!

    cout << "move ctor" << endl;
}

MyString::~MyString() { //destructor
    if (str) //very important!!!
        delete[] str;
    str = nullptr;
}

char *MyString::getStr() const {
    return str;
}

MyString &MyString::operator=(const MyString &ms) { //assignment operator
    len = ms.len;

    if (str)
        delete[] str;

    if (ms.str)
    {
        len = strlen(ms.str);
        str = new char[len + 1];
        strcpy(str,  ms.str);
    } else
        str = nullptr;
    return *this;
}

MyString &MyString::operator=(MyString &&ms) { // move assignment operator

    if (str)
        delete[] str;
    len = ms.len;
    str = ms.str; // steal (dont copy) rvalue's data
    ms.str = nullptr;
    cout << "move assign" <<endl;
    return *this;
}

char &MyString::operator[](int index) {
    if (index < 0 || index >= len){ // if index is not in bounds print error message
        cout << "ERROR" << endl;
        exit(0);// exit from program
    }
    return str[index]; // return data in str[index]
}

MyString MyString::insert(int index, const char *_str) { // insert string into our string and return results
    char *newStr = new char[index];// creating new _str to copy all data to return
    if (index < 0 || index > len){ // if index is not in bounds print error message
        cout << "ERROR" << endl;
        MyString temp(newStr);
        return temp;// return newStr // return empty stri
    }
    strncpy(newStr, _str, index); // copy data from str
    strcat(newStr, str); // subtract _str to the newStr
    strcat(newStr, _str+index); // subtract _str to the newStr
    MyString temp(newStr);
    return temp;// return newStr
}


MyString MyString::operator+(const MyString &ms) const { // addition operator
    int sizeI = len;
    int sizeII = ms.len;
    char *temp = new char[sizeI + sizeII + 1];

    strcpy(temp,  str);
    strcpy(temp + sizeI, ms.str);

    MyString x(temp);

    return x;
}

MyString MyString::operator*(const int num) const { // multiply operator
    char *temp;
    temp = new char[len * num + 1];

    for (int i = 0; i < num; i++)
        strcpy(temp + i * len,  str);

    MyString s(temp);

    return s;
}

bool MyString::operator==(const MyString &ms) const { // equality operator
    return !strcmp(str, ms.str);
}

bool MyString::operator!=(const MyString &rhs) const { // not equal operator
    return !(rhs == *this);
}


bool MyString::operator<(const MyString &rhs) const { // smaller operator
    return (strcmp(str, rhs.str) < 0);
}

bool MyString::operator>(const MyString &rhs) const { // grater operator
    return (strcmp(str, rhs.str) > 0);
}

bool MyString::operator<=(const MyString &rhs) const { // smaller or equal operator
    return !(rhs < *this);
}

bool MyString::operator>=(const MyString &rhs) const { // grater or equal operator
    return !(*this < rhs);
}

ostream &operator<<(ostream &os, const MyString &ms) { // ostream operator
    if (ms.str)
        os << ms.str << endl;
    return os;
}

istream &operator>>(istream &is, MyString &ms) { // istream operator
    ms.str = new char;
    is >> ms.str;
    ms.len = strlen(ms.str);
    return is;
}


