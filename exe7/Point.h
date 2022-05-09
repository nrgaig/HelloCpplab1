/* Created by Maor Frost 206370231 and Itay Oren 318648482
 * cpp lab - Meir Litman
 * exercise 2 task 1
 * class header represents Point in plain
 */
#ifndef HELLOCPPLAB1_POINT_H
#define HELLOCPPLAB1_POINT_H
#include <iostream>


class Point {
public:
    Point();

    Point(int x, int y);

    Point(Point const &copy);

    int getX();

    int getY();

    void setX(int x);

    void setY(int y);

    float distance(Point point);

    friend std::istream &operator>>(std::istream &in, Point &point);

private:
    int x;
    int y;


};


#endif //HELLOCPPLAB1_POINT_H
