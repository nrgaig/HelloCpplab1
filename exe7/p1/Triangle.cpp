/***********************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482 *
 * cpp lab - Meir Litman                                   *
 * exercise # task #                                       *
 * $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$               *
************************************************************/

#ifndef HELLOCPPLAB1_TRIANGLE_CPP
#define HELLOCPPLAB1_TRIANGLE_CPP
#include "Shape.cpp"
#include <cmath>

class Triangle : public Shape{
public:
    Triangle() : Shape(3){} //empty ctor

    bool isSpecial() const override{//checking if Triangle is equilateral
        double dist=points[0].distance(points[1]);//distance of first side
        if(dist!=points[1].distance(points[2])||dist!=points[2].distance(points[0]))
            return false;
        return true;
    }

    void printSpecial() const override{ // if Triangle is equilateral print it otherwise do nothing
        if (isSpecial())
            cout<<"An equilateral triangle with a side length "<<points[0].distance(points[1])<<"\n";
    }

    double area() const override{ // return area of Triangle using Heron's formula
        float s=(points[0].distance(points[1])+points[1].distance(points[2])+points[2].distance(points[0]))/2.0;
        return sqrt(s*(s-points[0].distance(points[1]))*(s-points[1].distance(points[2]))*(s-points[0].distance(points[2])));
    }
};


#endif //HELLOCPPLAB1_TRIANGLE_CPP