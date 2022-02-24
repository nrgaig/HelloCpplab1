/* Created by Maor Frost 206370231 and Itay Oren 318648482
 * cpp lab - Meir Litman
 * exercise 2 task 1
 * 
 */
#include "Polygon.h"

Point *Polygon::getVertex() const {
    return vertex;
}

void Polygon::setVertex(Point *vertex) {
    Polygon::vertex = vertex;
}

int Polygon::getNumOfVertexes() const {
    return num_of_vertexes;
}

void Polygon::setNumOfVertexes(int numOfVertexes) {
    num_of_vertexes = numOfVertexes;
}

Polygon::Polygon() {

}

Polygon::Polygon(int x, int y) {

}

Polygon::Polygon(const Polygon &copy) {

}
