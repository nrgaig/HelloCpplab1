/* Created by Maor Frost 206370231 and Itay Oren 318648482
 * cpp lab - Meir Litman
 * exercise 1 task 3
 * getting details of 3 circles and some points an printing how much points contains in each circle
 */
#include "circle.h"
#include "Point.h"
#include <iostream>

using namespace std;

//main function
int main() {
    int x, y, radius;
    char trash;
    Circle A;
    Circle B;
    Circle C;

    //asking from user to enter circle details
    cout << "enter the center point and radius of 3 circles:" << endl;
    cin >> trash >> x >> trash >> y >> trash >> radius;
    A.setCenter(x, y);
    A.setRadius(radius);
    cin >> trash >> x >> trash >> y >> trash >> radius;
    B.setCenter(x, y);
    B.setRadius(radius);
    cin >> trash >> x >> trash >> y >> trash >> radius;
    C.setCenter(x, y);
    C.setRadius(radius);

    //printing area and perimeter of each circle. asking from user to enter points
    cout << "perimeter: A: "<< A.perimeter()<< " B: " << B.perimeter() << " C: " << C.perimeter() << endl <<
            "area: A: " << A.area() << " B: " << B.area() << " C: " << C.area() << endl
             << "enter points until (0,0):" << endl;

    Point p;
    int caunterA=0;
    int caunterB=0;
    int caunterC=0;

    //getting points details from user
    while (cin >> trash >> x >> trash >> y >> trash){//while points are entered do:
        if (x == 0 && y == 0)// if the point is (0,0) finnish the loop
            break;
        p.setX(x);//set p(x)
        p.setY(y);//set p(y)
        if (A.onInOut(p) <= 0)//if point is in circle A
            caunterA++;

        if (B.onInOut(p) <= 0)//if point is in circle B
            caunterB++;

        if (C.onInOut(p) <= 0)//if point is in circle C
            caunterC++;

    }

    //printing results
    cout << "num of points in circle: A: " << caunterA << " B: " << caunterB << " C: " << caunterC;

}//end of main
/*
enter the center point and radius of 3 circles:
(0,0)3
(1,1)2
(5,5)2
perimeter: A: 18.84 B: 12.56 C: 12.56
area: A: 28.26 B: 12.56 C: 12.56
enter points until (0,0):
(0,1)(1,0) (0,4) (0,0)
num of points in circle: A: 2 B: 2 C: 0
 */
