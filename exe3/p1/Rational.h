/****************************************************
  Created by Maor Frost 206370231 and Itay Oren 318648482
  cpp lab - Meir Litman
  exercise 3 task 1
****************************************************/


#ifndef Q1_RATIONAL_H
#define Q1_RATIONAL_H

class Rational {
public:
    Rational();

    Rational(int _numerator, int _denominator);

    Rational(Rational const &copy);

    void setNumerator(int);

    void setDenominator(int);

    int getNumerator() const;

    int getDenominator() const;

    void print() const;

    bool equal(const Rational&) const;

    void reduction();

    Rational operator+(const Rational& rat) const;

private:
    int numerator{};
    int denominator{};
};

#endif //Q1_RATIONAL_H