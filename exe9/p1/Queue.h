//
// Created by itayo on 19/05/2022.
//

#ifndef HELLOCPPLAB1_QUEUE_H
#define HELLOCPPLAB1_QUEUE_H


#include <iostream>

using namespace std;

class Queue {
public:
    virtual ~Queue() {};

    virtual void clear() = 0;

    virtual void enqueue(int value) = 0;

    virtual int dequeue() = 0;

    virtual int front() = 0;

    virtual bool isEmpty() const = 0;
};


#endif //HELLOCPPLAB1_QUEUE_H
