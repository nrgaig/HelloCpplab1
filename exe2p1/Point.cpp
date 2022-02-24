/* Created by Maor Frost 206370231 and Itay Oren 318648482
 * cpp lab - Meir Litman
 * exercise 1 task 3
 * class header represents Point in plain
 */

#include <cmath>
#include "Point.h"

Point::Point() {}//empty constructor

Point::Point(int inX, int inY)  {//constructor
    x=inX;
    y=inY;
}

Point::Point(Point &copy) {//copy constructor
    Point::x=copy.getX();
    Point::y=copy.getY();
}

float Point::distance(Point point) {
    return sqrt(pow(point.x- this->x,2)+pow(point.y- this->y,2));
}

int Point::getX()  {
    return x;
}

int Point::getY()  {
    return y;
}

void Point::setX(int x) {
    Point::x = x;
}

void Point::setY(int y) {
    Point::y = y;
}
