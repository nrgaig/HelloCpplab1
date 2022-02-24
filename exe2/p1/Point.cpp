/* Created by Maor Frost 206370231 and Itay Oren 318648482
 * cpp lab - Meir Litman
 * exercise 2 task 1
 * class header represents Point in plain
 */

#include <cmath>
#include "Point.h"

Point::Point() {}//empty constructor

Point::Point(int inX, int inY)  {//constructor
    x=inX;
    y=inY;
}

Point::Point(const Point &copy) {//copy constructor
    Point::x=copy.x;
    Point::y=copy.y;
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
