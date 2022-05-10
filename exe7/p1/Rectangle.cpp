//
// Created by itayo on 10/05/2022.
//

#ifndef HELLOCPPLAB1_RECTANGLE_H
#define HELLOCPPLAB1_RECTANGLE_H

#include "Shape.cpp"

class Rectangle : public Shape {
public:
    Rectangle() : Shape(4) {};

    bool isSpecial() const override {
        double oneSide = points[0].distance(points[1]);
        for (int i = 1; i < 3; ++i) {
            if (points[i].distance(points[(i + 1)]) != oneSide)
                return false;
        }
        return (points[3].distance(points[(0)]) == oneSide);
    }

    void printSpecial() const override {
        if (isSpecial())
            cout << "Square with side length " << points[0].distance(points[1]) << endl;
    }

    double area() const override {
        return points[0].distance(points[1]) * points[1].distance(points[2]);
    }
};

#endif //HELLOCPPLAB1_RECTANGLE_H