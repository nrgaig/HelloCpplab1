/***********************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482 *
 * cpp lab - Meir Litman                                   *
 * exercise 9 task 1                                       *
 * abstract template class implements Queue for any type   *
************************************************************/

#ifndef HELLOCPPLAB1_QUEUE_H
#define HELLOCPPLAB1_QUEUE_H


#include <iostream>

using namespace std;
template<class T>
class Queue {
public:
    virtual ~Queue() {};

    virtual void clear() = 0;

    virtual void enqueue(T value) = 0;

    virtual T dequeue() = 0;

    virtual T front() = 0;

    virtual bool isEmpty() const = 0;
};


#endif //HELLOCPPLAB1_QUEUE_H
