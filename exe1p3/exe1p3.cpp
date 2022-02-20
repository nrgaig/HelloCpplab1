#include "circle.h"
#include "Point.h"
#include <iostream>

using namespace std;

int main() {
    int x, y, re;
    char trash;
    Circle A{};
    Circle B{};
    Circle C{};
    cout << "enter the center point and radius of 3 circles:" << endl;
    cin >> trash >> x >> trash >> y >> trash >> re;
    A.setCenter(x, y);
    A.setRadius(re);
    cin >> trash >> x >> trash >> y >> trash >> re;
    B.setCenter(x, y);
    B.setRadius(re);
    cin >> trash >> x >> trash >> y >> trash >> re;
    C.setCenter(x, y);
    C.setRadius(re);
    cout << "perimeter: A: "<< A.perimeter()<< " B: " << B.perimeter() << " C: " << C.perimeter() << endl <<
            "area: A: " << A.area() << " B: " << B.area() << " C: " << C.area() << endl
             << "enter points until (0,0):" << endl;
    x=1;
    y=1;
    Point p;
    int caunterA=0;
    int caunterB=0;
    int caunterC=0;
    while (x != 0 && y != 0){
        cin >> trash >> x >> trash >> y >> trash;
        p.setX(x);
        p.setY(y);
        if (A.onInOut(p) <= 0)
            caunterA++;

        if (B.onInOut(p) <= 0)
            caunterB++;

        if (C.onInOut(p) <= 0)
            caunterC++;

    }
    cout << "num of points in circle: A: " << caunterA << " B: " << caunterB << " C: " << caunterC;
}