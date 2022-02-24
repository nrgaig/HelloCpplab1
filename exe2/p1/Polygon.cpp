/* Created by Maor Frost 206370231 and Itay Oren 318648482
 * cpp lab - Meir Litman
 * exercise 2 task 1
 * 
 */
#include "Polygon.h"

Polygon::Polygon() { //empty constructor
    numOfVertexes = 0;
    vertex = nullptr;
}

Polygon::Polygon(int vertexesNum) { // constructor
    vertex = new Point [vertexesNum];
}

Polygon::Polygon(const Polygon &copy) { // copy constructor
    numOfVertexes = copy.numOfVertexes;//coppy num of vertexes
    vertex = new Point [numOfVertexes];//create new ponts array

    for (int i = 0; i < numOfVertexes; ++i) {//copy all points from other array to this->points array
        vertex[i] = copy.vertex[i];
    }
}

Polygon::~Polygon() {// distractor

}

Point *Polygon::getVertex() const {
    return vertex;
}

void Polygon::setVertex(Point *vertex) {
    vertex = vertex;
}

int Polygon::getNumOfVertexes() const {
    return numOfVertexes;
}

void Polygon::setNumOfVertexes(int numOfVertexes) {
    numOfVertexes = numOfVertexes;
}




