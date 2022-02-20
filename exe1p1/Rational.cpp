#include "Rational.h"
#include <iostream>

using namespace std;

Rational::Rational() {

}

void Rational::setNumerator(int num) {
    numerator = num;
}

void Rational::setDenominator(int num) {
    if (num == 0) {
        denominator = 1;
    }
    else if (num < 0) {
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

void Rational::print() {
    cout << numerator << "/" << denominator;
}

bool Rational::equal(Rational rat) {
    if (rat.denominator == denominator && rat.numerator == numerator)
        return true;
    return false;
}

Rational Rational::add(Rational rat) {
    Rational newNum;
    newNum.numerator = rat.numerator * denominator + numerator * rat.denominator;
    newNum.denominator = denominator * rat.denominator;
    newNum.reduction();
    return newNum;
}

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

