/* Created by Maor Frost 206370231 and Itay Oren 318648482
 * cpp lab - Meir Litman
 * exercise 1 task 3
 * class header represents Point in plain
 */
#ifndef HELLOCPPLAB1_POINT_H
#define HELLOCPPLAB1_POINT_H


class Point {
public:
    Point();

    Point(int x, int y);

    Point(Point  &copy);

    int getX() ;

    int getY() ;

    void setX(int x);

    void setY(int y);

    float distance(Point point);

private:
    int x;
    int y;


};


#endif //HELLOCPPLAB1_POINT_H
