/****************************************************
  Created by Maor Frost 206370231 and Itay Oren 318648482
  cpp lab - Meir Litman
  exercise 3 task 1
****************************************************/

#include "Rational.h"
#include <iostream>

using namespace std;

Rational::Rational()
{ // empty constructor
    numerator = 1;
    denominator = 1;
}

Rational::Rational(int _numerator, int _denominator)
{ // constructor
    this->setNumerator(_numerator);
    this->setDenominator(_denominator);
}

Rational::Rational(const Rational &copy)
{ // copy constructor
    numerator = copy.numerator;
    denominator = copy.denominator;
}

void Rational::setNumerator(int num)
{
    numerator = num;
}

void Rational::setDenominator(int num)
{
    // if it get denominator 0 it is illegal in math so it set to 1
    if (num == 0)
    {
        denominator = 1;
    }
    else if (num < 0)
    { // if it get negative denominator it make it positive and negative the numerator
        denominator = num * -1;
        numerator *= -1;
    }
    else
        denominator = num;
}

int Rational::getNumerator() const
{
    return numerator;
}

int Rational::getDenominator() const
{
    return denominator;
}

void Rational::print() const
{ // printing Rational number as it in paper (n/d)
    (denominator == 1) ? cout << numerator : cout << numerator << "/" << denominator;
}

Rational Rational::operator++(int trash)
{                                       // ++i (addindg 1 to this rational number postfix)
    Rational temp = *this;              // creating new rational number equal to this Rational
    temp.numerator += temp.denominator; // adding denominator value to numerator as we adding 1 to the number
    return temp;
}

Rational &Rational::operator++()
{                             // i++ (addindg 1 to this rational number prefix)
    numerator += denominator; // adding denominator value to numerator as we adding 1 to the number
    return *this;
}

Rational Rational::operator--(int trash)
{ // --i operator subtract rational number by 1 postfix

    Rational temp = *this;    // creating new rational number equal to this Rational
    numerator -= denominator; // substract denominator value from numerator as we adding 1 to the number
    return temp;
}

Rational &Rational::operator--()
{ // i-- operator subtraction rational number by 1 prefix
    numerator -= denominator;
    return *this;
}

Rational Rational::operator+(const Rational &rat) const
{ // + operator add other Rational to 'this' and return the result
    Rational newNum;
    newNum.numerator = rat.numerator * denominator + numerator * rat.denominator;
    newNum.denominator = denominator * rat.denominator;
    newNum.reduction();
    return newNum;
}

Rational Rational::operator-(const Rational &rat) const
{ // - operator substruct other Rational from 'this' and return the result
    int newNumerator = numerator * rat.denominator - rat.numerator * denominator;
    int newDenominator = denominator * rat.denominator;
    Rational temp(newNumerator, newDenominator);
    return temp;
}

Rational Rational::operator*(const Rational &rat) const
{ // * operator multiply other Rational with 'this' and return the result
    int newNumerator = numerator * rat.numerator;
    int newDenominator = denominator * rat.denominator;
    return Rational(newNumerator, newDenominator);
}

Rational Rational::operator/(const Rational &rat) const
{ // / operator divide other Rational with 'this' and return the result
    int newNumerator = numerator / rat.denominator;
    int newDenominator = denominator / rat.numerator;
    return Rational(newNumerator, newDenominator);
}

bool Rational::operator==(const Rational& num) const {
    Rational temp1 = *this;
    Rational temp2 = num;
    temp1.reduction();
    temp2.reduction();
    return temp1.numerator == temp2.numerator &&
           temp1.denominator == temp2.denominator;
}


bool Rational::operator!=(const Rational &rhs) const
{ //!= operator checking if rhs is not equal to this Rational
    return !(rhs == *this);
}

bool Rational::operator<(const Rational &rhs) const
{ // < operator, check if this small then rhs.
    if (numerator < rhs.numerator)
        return true;
    if (rhs.numerator < numerator)
        return false;
    return denominator < rhs.denominator;
}

bool Rational::operator>(const Rational &rhs) const
{ // > operator, check if this big then rhs.
    return rhs < *this;
}

bool Rational::operator<=(const Rational &rhs) const
{ // <= operator, check if this equal or small then rhs.
    return !(rhs < *this);
}

bool Rational::operator>=(const Rational &rhs) const
{ // >= operator, check if this equal or big then rhs.
    return !(*this < rhs);
}

// reducing the number to minimal rational number
void Rational::reduction()
{
    for (int i = min(abs(denominator), abs(numerator)); i >= 2; i--)
    {
        if (denominator % i == 0 && numerator % i == 0)
        {
            numerator /= i;
            denominator /= i;
            // TODO break?????
        }
    }
    if (numerator == 0)
        denominator = 1;
}
