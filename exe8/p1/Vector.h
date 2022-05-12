//
// Created by Maor on 12.5.2022.
//

#ifndef HELLOCPPLAB1_VECTOR_H
#define HELLOCPPLAB1_VECTOR_H

#include <iostream>

using namespace std;

const int DEF_CAPACITY = 100;

template<class T>
class Vector {
protected:
    T *data;
    int size;        //size in use
    int capacity;    //available capacity
public:
    //constructors
    Vector(int newCap = DEF_CAPACITY);

    Vector(const Vector<T> &v);

    ~Vector();

    //operations
    Vector<T> &operator=(const Vector<T> &);

    //modify
    T &operator[](int index);

    //or
    //view
    const T &operator[](int index) const;

    int getSize() const;

    int getCapacity() const;

    void insert(T value);

    void clear();

    T delLast();

    bool isEmpty() const;
};


//=======class Vector implementation=====
template<class T>
Vector<T>::Vector(int newCap) {//ctor
    capacity = newCap;
    size = 0;
    data = new T[capacity];
    if (data == NULL)
        throw "memory allocation problem";
}

template<class T>
Vector<T>::Vector(const Vector<T> &vec) {// copy ctor
    capacity = vec.capacity;
    size = vec.size;
    data = new T[capacity];
    if (data == NULL)
        throw "memory allocation problem";
    for (int index = 0; index < size; index++)
        data[index] = vec.data[index];
}

template<class T>
Vector<T>::~Vector() { // dtor
    if (data != NULL) {
        delete[] data;
        data = NULL;
    }
}

template<class T>
void Vector<T>::clear() {
    size = 0;
}

//modify function
//Vector v;
//v[6] = 7; //modify
//cout << v[6]; //view
template<class T>
T &Vector<T>::operator[](int index) {
    if (index < 0 || index >= size)
        throw
        "vector overflow";
    return data[index];
}

/*
//or view function
//Vector v;
//v[6] = 7; //modify is not allowed!!!
//cout << v[6]; //view is allowed

template <class T>
const T& Vector<T>::operator[](int index) const
{
	if (index < 0 || index >= size)
		throw "vector overflow";
	return data[index];
}
*/


template<class T>
Vector<T> &Vector<T>::operator=(const Vector<T> &vec) {
    size = vec.size;
    capacity = vec.capacity;

    if (data)
        delete[] data;
    data = new T[capacity];
    if (data == NULL)
        throw "memory allocation problem";
    for (int index = 0; index < size; index++)
        data[index] = vec.data[index];
    return *this;
}

template<class T>
int Vector<T>::getSize() const {
    return size;
}

template<class T>
int Vector<T>::getCapacity() const {
    return capacity;
}

template<class T>
void Vector<T>::insert(T value) {
    if (size >= capacity)
        throw "the vector is full";
    data[size] = value;
    size++;
}

template<class T>
T Vector<T>::delLast() {
    if (size < 0)
        throw "the vector is empty";
    return data[--size];
}

template <class T> bool Vector<T>::isEmpty() const {return size==0;} // return true if size == 0

#endif //HELLOCPPLAB1_VECTOR_H
