/****************************************************
  Created by Maor Frost 206370231 and Itay Oren 318648482
  cpp lab - Meir Litman
  exercise 3 task 2
  main program we asked to use from assigment
****************************************************/

#include <iostream>
#include "MyDate.h"

using namespace std;

enum options{STOP, UPDATE, PREFIX, POSTFIX, ASSIGN, IS_BIG, IS_SMALL, IS_EQUAL};

int main() {
    int day, month, year;
    char trash;
    cout << "Enter a date" << endl;
    cin >> day >> trash >> month >> trash >> year;
    MyDate initialDate(day,month,year);
    initialDate.print();
    int userSelection;
    do {
        cout << "\nEnter a code" << endl;
        cin >> userSelection;
        switch (userSelection){
            case STOP:
                break;
            case UPDATE: {
                cout << "Enter a date" << endl;
                cin >> day >> trash >> month >> trash >> year;
                initialDate.setDate(day, month, year);
                initialDate.print();
            }
                break;
            case PREFIX: {
                MyDate before;
                before = ++initialDate;
                before.print();
                cout << endl;
                initialDate.print();
                break;
            }
            case POSTFIX:{
                MyDate before;
                before = initialDate++;
                before.print();
                cout << endl;
                initialDate.print();
                break;
            }
            case ASSIGN:{
                cout << "Enter a date" << endl;
                cin >> day >> trash >> month >> trash >> year;
                MyDate tempDate(day,month,year);
                initialDate = tempDate;
                initialDate.print();
                break;
            }
            case IS_BIG:{
                cout << "Enter a date" << endl;
                cin >> day >> trash >> month >> trash >> year;
                MyDate tempDate(day,month,year);
                initialDate.print();
                cout << " > ";
                tempDate.print();
                cout <<" : ";
                initialDate > tempDate ? cout<< "true\n" : cout << "false\n";
                break;
            }
            case IS_SMALL:{
                cout << "Enter a date" << endl;
                cin >> day >> trash >> month >> trash >> year;
                MyDate tempDate(day,month,year);
                initialDate.print();
                cout << " < ";
                tempDate.print();
                cout <<" : ";
                initialDate < tempDate ? cout<< "true\n" : cout << "false\n";
                break;
            }
            case IS_EQUAL:{
                cout << "Enter a date" << endl;
                cin >> day >> trash >> month >> trash >> year;
                MyDate tempDate(day,month,year);
                initialDate.print();
                cout << "==";
                tempDate.print();
                cout <<" : ";
                initialDate == tempDate ? cout<< "true\n" : cout << "false\n";
                break;
            }
            default:
                cout << "ERROR" << endl;
                cin >> userSelection;

        }
    } while (userSelection != 0);

}