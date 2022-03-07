/***********************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482 *
 * cpp lab - Meir Litman                                   *
 * exercise 3 task 1                                       *
************************************************************/

#include"Rational.h"
#include <iostream>
using namespace std;

enum OPERATOR {
    EXIT, ADD_PRE, ADD_POST, SUB_PRE, SUB_POST, ADD, SUB, MULT, DIV,
    GREATER, LESS_THAN, GREATER_OR_EQUAL, LESS_OR_EQUAL, EQUAL, NOT_EQUAL};

void print(Rational rat1, Rational rat2, Rational  rat3, char op) {
    rat1.print();
    cout << " " << op << " ";
    rat2.print();
    cout << " = ";
    rat3.print();
    cout << endl;
}

void print(Rational rat1, Rational rat2, const char* op) {
    rat1.print();
    cout << " " << op << " ";
    rat2.print();
    cout << " ? ";
    cout << endl;
}

void printBefore(const char* op, Rational rat) {
    cout << "x = " << op << "y;" << endl;
    cout << "before operation y is: ";
    rat.print();
    cout << endl;
}

void printBefore(Rational rat, const char* op) {
    cout << "x = " << " y" << op << ";" << endl;
    cout << "before operation y is: ";
    rat.print();
    cout << endl;
}

void printAfter(Rational rat1, Rational rat2) {
    cout << "after operation x is: ";

    rat2.print();

    cout << endl << "y is: ";
    rat1.print();
    cout << endl;
}

int main()
{
    int numerator, denominator;
    char junk;
    int op;
    cout << "enter your choice:" << endl;
    cin >> op;
    Rational r2, r3;
    while (op != EXIT)	{
        cout << "enter a rational number:" << endl;
        cin >> numerator >> junk >> denominator;
        Rational r1(numerator, denominator);
        if (op >= 5) {
            cout << "enter a rational number:" << endl;
            cin >> numerator >> junk >> denominator;
            r2.setNumerator(numerator);
            r2.setDenominator(denominator);
        }
        switch (op)		{
            case ADD_PRE:
                printBefore("++", r1);
                r3 = ++r1;
                printAfter(r1, r3);
                break;
            case ADD_POST:
                printBefore(r1, "++");
                r3 = r1++;
                printAfter(r1, r3);
                break;
            case SUB_PRE:
                printBefore("--", r1);
                r3 = --r1;
                printAfter(r1, r3);
                break;
            case SUB_POST:
                printBefore(r1, "--");
                r3 = r1--;
                printAfter(r1, r3);
                break;
            case ADD:
                r3 = r1 + r2;
                print(r1, r2, r3, '+');
                break;
            case SUB:
                r3 = r1 - r2;
                print(r1, r2, r3, '-');
                break;
            case MULT:
                r3 = r1 * r2;
                print(r1, r2, r3, '*');
                break;
            case DIV:
                r3 = r1 / r2;
                print(r1, r2, r3, '/');
                break;
            case GREATER:
                print(r1, r2, ">");
                if (r1 > r2)
                    cout << "yes\n";
                else cout << "no\n";
                break;
            case LESS_THAN:
                print(r1, r2, "<");
                if (r1 < r2)
                    cout << "yes\n";
                else cout << "no\n";
                break;
            case GREATER_OR_EQUAL:
                print(r1, r2, ">=");
                if (r1 >= r2)
                    cout << "yes\n";
                else cout << "no\n";
                break;
            case LESS_OR_EQUAL:
                print(r1, r2, "<=");
                if (r1 <= r2)
                    cout << "yes\n";
                else cout << "no\n";
                break;
            case EQUAL:
                print(r1, r2, "==");
                if (r1 == r2)
                    cout << "yes\n";
                else cout << "no\n";
                break;
            case NOT_EQUAL:
                print(r1, r2, "!=");
                if (r1 != r2)
                    cout << "yes\n";
                else cout << "no\n";
                break;
        }
        cout << "enter your choice : " << endl;
        cin >> op;
    }

    return 0;
}
