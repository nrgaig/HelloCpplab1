/***********************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482 *
 * cpp lab - Meir Litman                                   *
 * exercise 8 task 2                                       *
 * Stack vector implementation                               *
************************************************************/
#include "StackVector.h"

//-------------------------------------------------------
//  class StackVector implementation
//-------------------------------------------------------


StackVector::StackVector(unsigned int capacity)
        : data(capacity)
{
    // create and initialize a Stack based on Vectors
}

void StackVector::clear()
{
    // clear all elements from Stack, by setting
    // index to bottom of Stack
    data.clear();
}

bool StackVector::isEmpty() const
{
    return data.getSize() == 0;
}

int StackVector::pop()
{
    // return and remove the intopmost element in the Stack
    if (isEmpty()) throw "Stack is empty";
    return data.delLast();
}


void StackVector::push(int val)
{
    // push new value onto Stack
    data.insert(val);
}

int StackVector::top() const
{
    // return the intopmost element in the Stack
    if (isEmpty()) throw "Stack is empty";
    return data[data.getSize() - 1];
}
