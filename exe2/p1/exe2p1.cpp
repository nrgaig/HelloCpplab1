
/* Created by Maor Frost 206370231 and Itay Oren 318648482
 * cpp lab - Meir Litman
 * exercise 2 task 1
 *
 */

#include "Polygon.h"
#include "Polygon.h"
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int numOfSides, X, Y;
    char trash;
    Point point;
    cout << "enter number of sides:" << endl;//asking enter input from user
    cin >> numOfSides;

    Polygon polygon1(numOfSides);

    cout << "enter the point values: " << endl;
    for (int i = 0; i < numOfSides; ++i) {
        cin >> trash >> X >> trash >> Y >> trash;
        if (X < 0 || Y < 0) {
            cout << "ERROR" << endl;
            continue;
        }
        point.setX(X);
        point.setY(Y);
        polygon1.addPoint(point, i);
    }
    cout << "enter number of sides:" << endl;//asking enter input from user
    cin >> numOfSides;

    Polygon polygon2(numOfSides);

    cout << "enter the point values: " << endl;
    for (int i = 0; i < numOfSides; ++i) {
        cin >> trash >> X >> trash >> Y >> trash;
        if (X < 0 || Y < 0) {
            cout << "ERROR" << endl;
            continue;
        }
        point.setX(X);
        point.setY(Y);
        polygon2.addPoint(point, i);
    }
    if (polygon1.equal(polygon2)){//if poligon 2 equals to polygon 1 peinr "equal" else preint "not equal"
        cout << "equal" << endl;
        cout << round(polygon1.perimeter());
    }
    else{
        cout << "not equal" << endl << round(polygon1.perimeter()) << endl << round(polygon2.perimeter());

    }

}

