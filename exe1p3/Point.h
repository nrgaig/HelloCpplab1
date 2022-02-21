/* Created by Maor Frost 206370231 and Itay Oren 318648482
 * cpp lab - Meir Litman
 * exercise 1 task 3
 * from the homework page
 */

#ifndef INC_12_POINT_H
#define INC_12_POINT_H



#pragma once
class Point
{
private:
    int x;
    int y;
public:
    void setX(int myX);
    void setY(int myY);
    int getX();
    int getY();
};



#endif //INC_12_POINT_H
