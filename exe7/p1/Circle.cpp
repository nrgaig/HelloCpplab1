/***********************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482 *
 * cpp lab - Meir Litman                                   *
 * exercise 7 task 1                                       *
 * class implement Circle based on Shape abstract class    *
************************************************************/

#ifndef HELLOCPPLAB1_CIRCLE_H
#define HELLOCPPLAB1_CIRCLE_H

#include "Shape.cpp"

const float PI = 3.14;

class Circle : public Shape {
public:
    explicit Circle(float _radius) : Shape(1) {
        radius = _radius;
    }

    // copy constructor
    Circle(const Circle &other) : Shape(other) {
        radius = other.radius;
    }

    bool isSpecial() const override {
        return this->points->getX() == 0 && this->points->getY() == 0;
    }

    void printSpecial() const override {
        if (this->isSpecial())
            cout << "A canonical circle with a radius " << radius << endl;
    }

    double area() const override {
        return PI * radius * radius;
    }

    // overloaded << operator
    friend ostream &operator<<(ostream &os, const Circle &circle) {
        os << (Shape &) circle;
        return os;
    }

protected:
    float radius;

};


#endif //HELLOCPPLAB1_CIRCLE_H