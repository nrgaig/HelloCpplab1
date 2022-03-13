/****************************************************
  Created by Maor Frost 206370231 and Itay Oren 318648482
  cpp lab - Meir Litman
  exercise 3 task 1
  class header represent rational number
****************************************************/

#ifndef HELLOCPPLAB1_RATIONAL_H
#define HELLOCPPLAB1_RATIONAL_H

class Rational
{
public:
  Rational();//empty constructor

  Rational(int _numerator, int _denominator); //constructor

  Rational(Rational const &copy); //copy constructor

  void setNumerator(int);

  void setDenominator(int);

  int getNumerator() const;

  int getDenominator() const;

  void print() const;

  void reduction(); // reducing the number to minimal rational number

  Rational operator++(int trash); // ++i (adding 1 to this rational number postfix)

  Rational &operator++(); // i++ (adding 1 to this rational number prefix)

  Rational operator--(int trash); // --i ( subtract rational number by 1 prefix)

  Rational &operator--(); // i-- (subtraction rational number by 1 prefix)

  Rational operator+(const Rational &rat) const;

  Rational operator-(const Rational &rat) const;

  Rational operator*(const Rational &rat) const;

  Rational operator/(const Rational &rat) const;

  //bool operator>(Rational rat);

  bool operator<(const Rational &rhs) const; // < operator, check if this smaller than rhs.

  bool operator>(const Rational &rhs) const; // > operator, check if this bigger than rhs.

  bool operator<=(const Rational &rhs) const; // <= operator, check if this equal or smaller than rhs.

  bool operator>=(const Rational &rhs) const; // >= operator, check if this equal or bigger than rhs.

  bool operator==(const Rational &rhs) const;

  bool operator!=(const Rational &rhs) const;

private:
  int numerator{};
  int denominator{};
};

#endif // HELLOCPPLAB1_RATIONAL_H
