/***********************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482 *
 * cpp lab - Meir Litman                                   *
 * exercise 7 task 1                                       *
 *                          *
************************************************************/

#ifndef HELLOCPPLAB1_SHAPE_H
#define HELLOCPPLAB1_SHAPE_H

#include "Shape.cpp"
#include <cmath>
#include <iostream>
using namespace std;

class Circle : public Shape {
public:


protected:
    float radius;
    Point center;

};


#endif //HELLOCPPLAB1_SHAPE_H