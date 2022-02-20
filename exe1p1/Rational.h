

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
