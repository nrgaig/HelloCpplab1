/****************************************************
  Created by Maor Frost 206370231 and Itay Oren 318648482
  cpp lab - Meir Litman
  exercise 3 task 1
****************************************************/


#include "Rational.h"
#include <iostream>

using namespace std;

Rational::Rational() {//empty constructor
    numerator = 1;
    denominator = 1;
}

Rational::Rational(int _numerator, int _denominator) { // constructor
    this->setNumerator(_numerator);
    this->setDenominator(_denominator);
}

Rational::Rational(const Rational &copy) { // copy constructor
    numerator = copy.numerator;
    denominator = copy.denominator;
}

void Rational::setNumerator(int num) {
    numerator = num;
}

void Rational::setDenominator(int num) {
    // if it get denominator 0 it is illegal in math so it set to 1
    if (num == 0) {
        denominator = 1;
    } else if (num < 0) {// if it get negative denominator it make it positive and negative the numerator
        denominator = num * -1;
        numerator *= -1;
    } else
        denominator = num;
}

int Rational::getNumerator() const {
    return numerator;
}

int Rational::getDenominator() const {
    return denominator;
}

void Rational::print() const { // printing Rational number as it in paper (n/d)
    (denominator == 1) ? cout << numerator : cout << numerator << "/" << denominator;

}

bool Rational::equal(const Rational& rat) const { //check if other Rational is equals with 'this' number
    if (rat.denominator == denominator && rat.numerator == numerator)
        return true;
    return false;
}

Rational Rational::operator+(const Rational& rat) const { // add other Rational to 'this' and return the result
    Rational newNum;
    newNum.numerator = rat.numerator * denominator + numerator * rat.denominator;
    newNum.denominator = denominator * rat.denominator;
    newNum.reduction();
    return newNum;
}

//reducing the number to minimal rational number
void Rational::reduction() {
    for (int i = min(abs(denominator), abs(numerator)); i >= 2; i--) {
        if (denominator % i == 0 && numerator % i == 0) {
            numerator /= i;
            denominator /= i;
            // TODO break?????
        }
    }
    if (numerator == 0)
        denominator = 1;
}





