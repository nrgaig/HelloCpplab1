#include <iostream>
#include <cmath>
#include "Vector.h"

using namespace std;

Vector::Vector(int temp ) {
    if(!isPowerOfTwo(temp)) {
        capacity = pow(2, ceil(log(temp) / log(2)));
    } else
        capacity = temp;
    data = new int[capacity];
    size = 0;
}

Vector::Vector(Vector const &copy) {
    capacity = copy.capacity;
    size = copy.size;
    data = new int[capacity];
    for (int i = 0; i < size; ++i) {
        data[i] = copy.data[i];
    }
}

Vector::~Vector() {
    if (data)
        delete [] data;
}
bool Vector::isPowerOfTwo(int n) {
    if (n == 0)
        return false;
    while (n != 1)
    {
        if (n%2 != 0)
            return false;
        n = n/2;
    }
    return true;
}

int Vector::getCapacity() const {
    return capacity;
}

int Vector::getSize() const {
    return size;
}
void Vector::print(){
    cout << "capacity: " << capacity << "size: " << size <<  "values: ";
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
}

void Vector::assign(Vector vec) {
    if (capacity != vec.capacity){
        data = new int[vec.capacity];
    } //TODO here
}

bool Vector::isEqual(Vector vec) {
    return false;
}

int &Vector::at(int index) {
    return ;
}

int Vector::scalmul(Vector vec) {
    return 0;
}

int *Vector::strnewcat(Vector vec) {
    return nullptr;
}

void Vector::clear() {

}

void Vector::delLast() {

}

void Vector::insert(int val) {

}


