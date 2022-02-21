//  Created by Maor Frost 206370231 Itay Oren 318648482
//  cpp lab - Meir Litman
//  exercise 1 task 1
//  class header for representing Rational number
//


#ifndef Q1_RATIONAL_H
#define Q1_RATIONAL_H
class Rational{
public:
    Rational();
    void setNumerator(int);
    void setDenominator(int);
    int getNumerator();
    int getDenominator();
    void print();
    bool equal(Rational);
    void reduction();
    Rational add(Rational);

private:
    int numerator;
    int denominator;
};
#endif //Q1_RATIONAL_H
