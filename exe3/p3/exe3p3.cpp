/****************************************************
  Created by Maor Frost 206370231 and Itay Oren 318648482
  cpp lab - Meir Litman
  exercise 3 task 3
  program present usage with class operators
****************************************************/

#include <iostream>
#include "MyString.h"
int main() {
    int num;
    char char1;
    MyString a;
    MyString b;
    //getting from user two strings and number
    cin >> a;
    cin >> b;
    cin >> num;

    // printing ratio between two strings
    cout << 'a';
    (a==b)? cout << '=': (a>b) ? cout << '>' : cout << '<';
    cout << 'b'<<endl;
    MyString temp;  // creating temp string
    temp = a.insert(num, b.getStr());//applying insert() function

    cout << temp << endl;   // printing result

    cin >> char1 >> num;    // getting from user character and number
    temp[num] = char1;      // insert character into temp
    cout << temp << endl;   // printing result




return 0;
}
