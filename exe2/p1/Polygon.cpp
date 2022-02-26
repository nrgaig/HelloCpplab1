/* Created by Maor Frost 206370231 and Itay Oren 318648482
 * cpp lab - Meir Litman
 * exercise 2 task 1
 * 
 */
#include "Polygon.h"
#include <iostream>

using namespace std;

Polygon::Polygon() { //empty constructor
    numOfVertexes = 0;
    vertex = nullptr;
    cout << "in empty constructor" << endl;
}

Polygon::Polygon(int vertexesNum) { // constructor
    numOfVertexes = vertexesNum;
    vertex = new Point [vertexesNum];
    cout << "in one parameter constructor" << endl;
}

Polygon::Polygon(const Polygon &copy) { // copy constructor
    numOfVertexes = copy.numOfVertexes;//coppy num of vertexes
    vertex = new Point [numOfVertexes];//create new ponts array

    for (int i = 0; i < numOfVertexes; ++i) {//copy all points from other array to this->points array
        vertex[i] = copy.vertex[i];
    }
    cout << "in copy constructor" << endl;
}

Polygon::~Polygon() {// distractor
    if (vertex != nullptr)// if array declared delete it
        delete[] vertex;
    cout << "in destructor" << endl;
}

Point* Polygon::getVertex() const {
    Point* temp = new Point [numOfVertexes];
    return temp;
}

int Polygon::getNumOfVertexes() const {
    return numOfVertexes;
}

void Polygon::addPoint(Point p, int index){
    vertex[index] = p; // TODO check if work in moodle
}
float Polygon::perimeter(){
    float ans = 0;
    for (int i = 0; i < numOfVertexes-1; ++i) {
        ans += vertex[i].distance(vertex[i+1]);//sum distance between every two points except between first and last
    }
    ans += vertex[numOfVertexes-1].distance(vertex[0]);//addin distance of last and first points
    return ans;
}

bool Polygon::equal(Polygon second) {
    if(numOfVertexes != second.numOfVertexes)
        return false;
    int caunt= 0;
    for (int i = 0; i < numOfVertexes; ++i) {
        for (int j = 0; j < numOfVertexes; ++j) {
            if(vertex[i].getX() == second.vertex[j].getX() && vertex[i].getY() == second.vertex[j].getY()){
                caunt++;
                break;
            }
        }
    }
    if(caunt == numOfVertexes)
        return true;
    return false;
}




