/****************************************************
  Created by Maor Frost 206370231 and Itay Oren 318648482
  cpp lab - Meir Litman
  exercise 3 task 3
  class for implementing String for better understanding operators
****************************************************/
#include <cstring>
#include "MyString.h"

MyString::MyString(const char *s) {//constructor
    if (s)  //if s is not empty copy values from s
    {
        len = strlen(s);    //copy len of s string
        str = new char[len + 1];// create new string with our new length
        strcpy(str, s); //copy string from s string
    } else  // if there isn't new string set str to null
        str = nullptr;

}

MyString::MyString(const MyString &ms)//copy constructor
        : MyString(ms.str) {
 }

MyString::MyString(MyString &&ms) {  // move constructor

    len = ms.len;
    str = ms.str; // steal (dont copy) rvalue's data
    ms.str = nullptr; //very important!!!  - make ms.str point to null to avoid deleting its data

    cout << "move ctor" << endl;
}

MyString::~MyString() { //destructor
    if (str) //very important!!! - if str is allocated then delete it
        delete[] str;
    str = nullptr;
}

char *MyString::getStr() const {
    return str;
}

MyString &MyString::operator=(const MyString &ms) { //assignment operator
    len = ms.len;   //set len to the assigned string len

    if (str)    //if there was allocated string delete it
        delete[] str;

    if (ms.str) // if there is new string copy values
    {
        len = strlen(ms.str);   //copy len
        str = new char[len + 1];    // create new string to copy
        strcpy(str,  ms.str);   //copy string data from ms.str
    } else  // if there isn't new string set str to null
        str = nullptr;
    return *this;
}

MyString &MyString::operator=(MyString &&ms) { // move assignment operator

    if (str)//if there was allocated string delete it
        delete[] str;
    len = ms.len;   //copy len
    str = ms.str;   // steal (dont copy) rvalue's data
    ms.str = nullptr;   //set ms.str to null
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
    char *temp = new char[sizeI + sizeII + 1];  // creating temp string (cstring) to copy all data

    strcpy(temp,  str);         // copy data from this->str
    strcpy(temp + sizeI, ms.str);//copy data from ms.str

    MyString x(temp);                        // enter temp string into new MyString to return

    return x;
}

MyString MyString::operator*(const int num) const { // multiply operator
    char *temp;        // creating temp string (cstring) to copy all data
    temp = new char[len * num + 1];// size of temp string is original-length*num

    for (int i = 0; i < num; i++)// copy data to temp
        strcpy(temp + i * len,  str);

    MyString s(temp);// enter temp string into new MyString to return

    return s;
}

bool MyString::operator==(const MyString &ms) const { // equality operator
    return !strcmp(str, ms.str);    // strcmp return 0 if both strings are equal so ew return the opposite to be true
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
    if (ms.str) //if there is some string to stream
        os << ms.str << endl;   // stream it to os
    return os;
}

istream &operator>>(istream &is, MyString &ms) { // istream operator
    ms.str = new char; //set new str in ms
    is >> ms.str;   //istream into ms.str
    ms.len = strlen(ms.str);// set ms.str ass length of the string we stream
    return is;
}


