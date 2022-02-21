/* Created by Maor Frost 206370231 and Itay Oren 318648482
* cpp lab - Meir Litman
* exercise 1 task 3
* class represent circle
*/

#include "circle.h"
#include <cmath>

#define PI 3.14

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

float Circle::perimeter() {
    return 2 * PI * radius;
}

//getting point and checking if point is in/on/out of the circle
// return -1 if in | return 0 if on | return 1 if out
int Circle::onInOut(Point p) {
    double distance = sqrt(pow(p.getX()-center.getX(),2)+ pow(p.getY()-center.getY(),2));
    if(distance > radius){
        return 1;
    } else if (distance == radius){
        return 0;
    } else{
        return -1;
    }
}

