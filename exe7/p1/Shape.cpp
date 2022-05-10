/***********************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482 *
 * cpp lab - Meir Litman                                   *
 * exercise 7 task 1                                       *
 * Abstract class represent Shape                          *
************************************************************/

#ifndef HELLOCPPLAB1_SHAPE_H
#define HELLOCPPLAB1_SHAPE_H

#include <cmath>
#include <iostream>

using namespace std;

class Shape {
protected:
    class Point {
    public:
        Point() : x(0), y(0) {}//empty constructor

        Point(int inX, int inY) : x(inX), y(inY) {} // constructor

        Point(const Point &copy) : x(copy.x), y(copy.y) {} // copy constructor

        double distance(const Point &point) const {
            return sqrt(pow(point.x - this->x, 2) + pow(point.y - this->y, 2));
        }

        int getX() const { return x; }

        int getY() const { return y; }

        void setX(int newX) { this->x = newX; }

        void setY(int newY) { this->y = newY; }

        friend istream &operator>>(istream &is, Point &ms) { //overloading >> operator
            int newX, newY;
            char trash;
            is >> trash >> newX >> trash >> newY >> trash;//input format: "(newX,newY)"
            ms.setX(newX);
            ms.setY(newY);
            return is;
        }

    private:
        int x;
        int y;


    };//end of class Point

protected: //properties
    int numOfPoints;
    Point *points;

public:
    explicit Shape(int numOfPoints) : numOfPoints(numOfPoints), points(new Point[numOfPoints]) {// ctor
        cout << "Enter values of  " << numOfPoints << " points: \n"; //asking input from user
        for (int i = 0; i < numOfPoints; ++i) {//running on array of points
            cin >>
                points[i]; //getting values from user
        }
    }//end ctor


    Shape() : numOfPoints(0), points(nullptr) {} // empty ctor

    Shape(const Shape &copy) : numOfPoints(copy.numOfPoints), points(new Point[numOfPoints]) { // deep copy ctor
        for (int i = 0; i < numOfPoints; ++i) {//running on array of points
            points[i].setX(copy.points[i].getX()); //copy x values
            points[i].setY(copy.points[i].getY()); //copy y values
        }
    }// end of copy ctor

    Shape(const Shape &&copy) noexcept: numOfPoints(copy.numOfPoints), points(copy.points) {}// move ctor

    virtual ~Shape() { delete[] points; } // dtor

    friend ostream &operator<<(ostream &os, Shape &shape) { // output for all points values in specific format
        // format: "points: (x1,y1) (x2, y2)... (xn,yn)"
        os << "points:";
        for (int i = 0; i < shape.numOfPoints; ++i) {
            os << " (" << shape.points[i].getX() << "," << shape.points[i].getY() << ")";
        }
        return os;
    }//end of operator<<

    virtual double area() const = 0; //return area of shape

    virtual bool isSpecial() const = 0;// return true if shape has special feature

    virtual void printSpecial() const = 0; // printing all special  features

};


#endif //HELLOCPPLAB1_SHAPE_H