/***********************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482 *
 * cpp lab - Meir Litman                                   *
 * exercise 8 task 2                                       *
 * Stack abstract class                                    *
************************************************************/

#ifndef HELLOCPPLAB1_STACK_H
#define HELLOCPPLAB1_STACK_H

//-------------------------------------------------------
//  class stack
//  abstract class - simply defines protocol for
//  stack operations
//-------------------------------------------------------

class Stack
{
public:
    virtual void clear() = 0;
    virtual bool isEmpty() const = 0;
    virtual int pop() = 0;
    virtual void push(int value) = 0;
    virtual int top() const = 0;
};



#endif //HELLOCPPLAB1_STACK_H
