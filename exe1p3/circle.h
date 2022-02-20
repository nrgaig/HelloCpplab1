//
// Created by itayo on 20/02/2022.
//

#ifndef INC_12_CIRCLE_H
#define INC_12_CIRCLE_H


#pragma once
#include "Point.h"
class Circle
{
private:
    Point center;
    int radius;
public:
    void setCenter(int x, int y);
    void setRadius(int myRadius);
    Point getCenter();
    int getRadius();
    float area();
    float perimeter();
    int onInOut(Point p);
};



#endif //INC_12_CIRCLE_H
