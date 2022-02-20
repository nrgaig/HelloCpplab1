//
// Created by itayo on 20/02/2022.
//

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

float Circle::area() {
    return PI * pow(radius, 2);
}

float Circle::perimeter() {
    return 2 * PI * radius;
}

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

