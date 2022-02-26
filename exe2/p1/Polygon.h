/* Created by Maor Frost 206370231 and Itay Oren 318648482
 * cpp lab - Meir Litman
 * exercise 2 task 1
 * 
 */
#ifndef HELLOCPPLAB1_POLYGON_H
#define HELLOCPPLAB1_POLYGON_H

#include "Point.h"

class Polygon {
public:
    Polygon();

    Polygon(int vertexesNum);

    Polygon(Polygon const &copy);

     ~Polygon();

    Point *getVertex() const;

    int getNumOfVertexes() const;

    void addPoint(Point p, int index);

    float perimeter();

    bool equal(Polygon second);

private:
    Point *vertex;
    int numOfVertexes;


};


#endif //HELLOCPPLAB1_POLYGON_H
