/* Created by Maor Frost 206370231 and Itay Oren 318648482
* cpp lab - Meir Litman
* exercise 1 task 3
* class represent circle
*/

#include "circle.h"
#include <cmath>

#define PI 3.14 // const PI

void Circle::setCenter(int x, int y) {
    center.setX(x);
    center.setY(y);
}

void Circle::setRadius(int myRadius) {
    radius = myRadius;
}

Point Circle::getCenter() {
    return center;
}

int Circle::getRadius() {
    return radius;
}
//calculate and return the area of circle
float Circle::area() {
    return PI * pow(radius, 2);
}
//calculate and return the perimeter of circle
float Circle::perimeter() {
    return 2 * PI * radius;
}

//getting point and checking if point is in/on/out of the circle
// return -1 if in | return 0 if on | return 1 if out
int Circle::onInOut(Point p) {
    //calculate distance from circle's center to the point
    double distance = sqrt(pow(p.getX() - center.getX(), 2) + pow(p.getY() - center.getY(), 2));
    if (distance > radius) {// if diatance is more than radius return 1
        return 1;
    } else if (distance == radius) {// if diatance is equals to radius return 0
        return 0;
    } else {// if diatance is less than radius return -1
        return -1;
    }
}

