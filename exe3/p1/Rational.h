/****************************************************
  Created by Maor Frost 206370231 and Itay Oren 318648482
  cpp lab - Meir Litman
  exercise 3 task 1
****************************************************/

#ifndef HELLOCPPLAB1_RATIONAL_H
#define HELLOCPPLAB1_RATIONAL_H

class Rational
{
public:
  Rational();

  Rational(int _numerator, int _denominator);

  Rational(Rational const &copy);

  void setNumerator(int);

  void setDenominator(int);

  int getNumerator() const;

  int getDenominator() const;

  void print() const;

  Rational operator++(int trash); // ++i (adding 1 to this rational number postfix)

  Rational &operator++(); // i++ (adding 1 to this rational number prefix)

  Rational operator--(int trash); // --i ( subtract rational number by 1 prefix)

  Rational &operator--(); // i-- (subtraction rational number by 1 prefix)

  Rational operator+(const Rational &rat) const;

  Rational operator-(const Rational &rat) const;

  Rational operator*(const Rational &rat) const;

  Rational operator/(const Rational &rat) const;

  bool operator>(Rational rat);

  bool operator<(Rational rat);

  bool operator>=(Rational rat);

  bool operator<=(Rational rat);

  bool operator==(Rational rat);

  bool operator!=(Rational rat);

  void reduction();

private:
  int numerator{};
  int denominator{};
};

#endif // HELLOCPPLAB1_RATIONAL_H
