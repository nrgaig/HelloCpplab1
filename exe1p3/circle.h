/* Created by Maor Frost 206370231 and Itay Oren 318648482
 * cpp lab - Meir Litman
 * exercise 1 task 3
 * from the homework page
 */

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
