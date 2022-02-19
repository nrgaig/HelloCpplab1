#include "Rational.h"
#include <iostream>

using namespace std;

Rational::Rational() {

}

void Rational::setNumerator(int num) {
    numerator = num;
}

void Rational::setDenominator(int num) {
    /*
     * problem wen get 0, the default value of denominator is 0.
     */
    if (num <= 0) { return; }
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
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 2; i <= min(denominator, numerator); ++i) {
            if (denominator % i == 0 && numerator % i == 0) {
                flag = true;
                numerator /= i;
                denominator /= i;
            }
        }
    }
    if (numerator == 0)
        denominator = 1;
}

