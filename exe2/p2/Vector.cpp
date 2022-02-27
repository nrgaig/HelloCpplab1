/* Created by Maor Frost 206370231 and Itay Oren 318648482
 * cpp lab - Meir Litman
 * exercise 2 task 2
 * implement methods to manage vectors
 */
#include <iostream>
#include <cmath>
#include "Vector.h"

using namespace std;

// constructor
Vector::Vector(int temp) {
    if (!isPowerOfTwo(temp)) {// if temp is not power of 2
        capacity = newPowerOfTwo(temp);//assign in capacity nearest number that powers of 2
    } else
        capacity = temp; // if temp is power of 2 assign in capacity
    data = new int[capacity]; // new array with correct capacity
    size = 0;
}

// copy constructor
Vector::Vector(Vector const &copy) {
    //coping data from &copy to new Vector object
    capacity = copy.capacity;
    size = copy.size;
    data = new int[capacity];
    for (int i = 0; i < size; ++i) {
        data[i] = copy.data[i];
    }
}

//distractor
Vector::~Vector() {
    delete[] data; // delete the allocated array
}

bool Vector::isPowerOfTwo(int n) { // checking if number is power of 2
    if (n == 0)
        return false;
    while (n != 1) {
        if (n % 2 != 0)//if the number is not devides by 2
            return false;
        n = n / 2;
    }
    return true;//if the number is devides by 2
}

int Vector::newPowerOfTwo(int num) { // return new power of two
    return pow(2, ceil(log(num) / log(2)));
}


int Vector::getCapacity() const {
    return capacity;
}

int Vector::getSize() const {
    return size;
}

//printing capacity, size and values of vector
void Vector::print() {
    cout << "capacity: " << capacity << "size: " << size << "values: ";
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
}

//coping values from vec to existing Vector
void Vector::assign(Vector vec) {
    if (capacity != vec.capacity) {//if the capacity is deferment make new array with new capacity
        delete[] data;//deleting old data array (dynamic allocating)
        data = new int[vec.capacity];//allocating new array with vec's capacity
        capacity = vec.capacity;// giving new capacity
    }
    size = vec.size;// giveing new size
    for (int i = 0; i < size; ++i) { // copy all the data from other to this
        data[i] = vec.data[i];
    }
}

//checking if vector is equal to other vector
bool Vector::isEqual(Vector vec) {
    if (size != vec.size)// if they difers in size return false
        return false;
    for (int i = 0; i < size; ++i) {//if size equal run on every member in arrays
        if (data[i] != vec.data[i]) // if in some index there are different valiuse return false
            return false;
    }
    return true; // if all the data the same return true
}

// returns value in index in data array
int &Vector::at(int index) {
    if (index > size) { // if index is out of bound, print "error" and return first cell in the data array
        cout << "ERROR" << endl;
        return *data;
    }
    return *(data + index); // return the cell in data
}

// doing scallar multipling and return the result
int Vector::scalmul(Vector vec) {
    if (size != vec.size) { // if the size is defrent no multiplation can be done
        cout << "ERROR" << endl;
        return -1;
    }
    int sum = 0;
    for (int i = 0; i < size; ++i) { // for every cell in each vector do:
        sum += data[i] * vec.data[i]; // multiply every two cells and add them to the sum
    }
    return sum; // return the sum
}

//
Vector Vector::strnewcat(Vector vec) {
    int newCapacity = capacity + vec.capacity;
    if (!isPowerOfTwo(newCapacity)) {// if sum of capacities is not power of 2
        newCapacity = newPowerOfTwo(capacity + vec.capacity); // get a new power of two
    }
    Vector newVec(newCapacity);// creating new vector with new capacity
    newVec.size = size + vec.size;// new vector size is sum of both
    for (int i = 0; i < size; ++i) {//coping values of first Vector
        newVec.data[i] = data[i];
    }
    for (int i = 0; i < vec.size; ++i) {
        newVec.data[i + size] = vec.data[i];//coping values of second Vector
    }
    return newVec;//return the new Vector
}

//clear all values in data array
void Vector::clear() {
    capacity = 0;
    size = 0;
    delete[] data;
    data = nullptr;
    //TODO moodel will tell us
}

//delete the last cell in vector array
void Vector::delLast() {
    if (size == 0) {//if size is 0 print ERROR
        cout << "ERROR" << endl;
        return;
    }
    //if size is more than 0
    data[size - 1] = 0;//deleting last cell
    size--;//sizing down
}

//insert new value into the Vector
void Vector::insert(int val) {
    if (size == capacity) {//if the vector is full
        capacity *= 2;//make the capacity double in size
        int *tempData = new int[capacity]; //temp array to store old data
        for (int i = 0; i < size; ++i) { //coping old data to new temp array
            tempData[i] = data[i];
        }
        delete[] data;//deleting old data array
        data = tempData;//making data point to the array of tempdata
        tempData = nullptr;//making tempData point to null
    }
    data[size] = val;//adding val to the data array
    size++;//sizing up
}


