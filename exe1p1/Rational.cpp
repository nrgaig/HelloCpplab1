//  Created by Maor Frost 206370231 Itay Oren 318648482
//  cpp lab - Meir Litman
//  exercise 1 task 1
//  class for representing Rational number
//


#include "Rational.h"
#include <iostream>

using namespace std;

Rational::Rational() {//default constructor

}

void Rational::setNumerator(int num) {
    numerator = num;
}

void Rational::setDenominator(int num) {
    // if it get denominator 0 it is illegal in math so it set to 1
    if (num == 0) {
        denominator = 1;
    }
    else if (num < 0) {// if it get negative denominator it make it positive and negative the numerator
        denominator = num * -1;
        numerator *= -1;
    } else
        denominator = num;
}

int Rational::getNumerator() {
    return numerator;
}

int Rational::getDenominator() {
    return denominator;
}

void Rational::print() { // printing Rational number as it in paper (n/d)
    cout << numerator << "/" << denominator;
}

bool Rational::equal(Rational rat) { //check if other Rational is equals with 'this' number
    if (rat.denominator == denominator && rat.numerator == numerator)
        return true;
    return false;
}

Rational Rational::add(Rational rat) { // add other Rational to 'this' and return the result
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
        }
    }
    if (numerator == 0)
        denominator = 1;
}

