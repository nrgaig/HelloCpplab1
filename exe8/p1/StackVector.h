/***********************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482 *
 * cpp lab - Meir Litman                                   *
 * exercise # task #                                       *
 * $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$               *
************************************************************/
#ifndef HELLOCPPLAB1_STACKVECTOR_H
#define HELLOCPPLAB1_STACKVECTOR_H

#include "Vector.h"         //homework targil 2 !
//#include "Stack.h"

//-------------------------------------------------------
// class stack
// abstract class - simply defines protocol for
// stack operations
//-------------------------------------------------------
template <class T>
class Stack
{
public:
    virtual void clear() = 0;
    virtual bool isEmpty() const = 0;
    virtual T pop() = 0;
    virtual void push(int value) = 0;
    virtual T top() = 0;
};



//-------------------------------------------------------
//  class StackVector
//  Stack implemented using Vector
//  Vector will grow as necessary to avoid overflow
//-------------------------------------------------------

template <class T>
class StackVector : public Stack<T>
{
public:
    // constructor requires a starting size
    StackVector(unsigned int capacity=100);
    StackVector(const StackVector& s);

    // Stack operations
    void clear() override;
    bool isEmpty() const override;
    T pop() override;
    void push(int value) override;
    T top()override;
protected:
    // data fields
    Vector<T> data;
};


//-------------------------------------------------------
//  class StackVector implementation
//-------------------------------------------------------

template <class T>
StackVector<T>::StackVector(unsigned int capacity)
        : data()
{
    // create and initialize a Stack based on Vectors

}
template <class T>
void StackVector<T>::clear()
{
    // clear all elements from Stack, by setting
    // index to bottom of Stack
    data.clear();
}
template <class T>
bool StackVector<T>::isEmpty() const
{
    return data.getSize() == 0;
}
template <class T>
T StackVector<T>::pop()
{
    // return and remove the intopmost element in the Stack
    if (isEmpty()) throw "Stack is empty";
    return data.delLast();
}

template <class T>
void StackVector<T>::push(int val)
{
    // push new value onto Stack
    data.insert(val);
}
template <class T>
T StackVector<T>::top()  {
    // return the intopmost element in the Stack
    if (isEmpty()) throw "Stack is empty";
    return data[data.getSize() - 1];
}

template<class T>
StackVector<T>::StackVector(const StackVector &s) : data(s.data){

}


#endif //HELLOCPPLAB1_STACKVECTOR_H
