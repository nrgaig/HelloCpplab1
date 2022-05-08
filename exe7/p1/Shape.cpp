/***********************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482 *
 * cpp lab - Meir Litman                                   *
 * exercise 7 task 1                                       *
 * Abstarct class represent Shape                          *
************************************************************/

#ifndef HELLOCPPLAB1_SHAPE_H
#define HELLOCPPLAB1_SHAPE_H

#include <cmath>
#include <iostream>
using namespace std;

class Shape {
    class Point {
    public:
        Point():x(0), y(0) {}//empty constructor

        Point(int inX, int inY): x(inX), y(inY) {} // constructor

        Point(const Point &copy):x(copy.x), y(copy.y) {} // copy constructor



        float distance(Point point) {
            return sqrt(pow(point.x- this->x,2)+pow(point.y- this->y,2));
        }

        int getX()  {return x;}

        int getY()  {return y;}

        void setX(int x) {Point::x = x;}

        void setY(int y) {y = y;}

        friend istream & operator>>(istream &is, Point &ms) { //overloading >> operator
            int x,y;
            char trash;
            is >> trash >> x >> trash >> y >> trash;
            ms.setX(x);
            ms.setY(y);
        }

    private:
        int x;
        int y;


    };

protected:

};


#endif //HELLOCPPLAB1_SHAPE_H