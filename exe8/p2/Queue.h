/***********************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482 *
 * cpp lab - Meir Litman                                   *
 * exercise 8 task 2                                       *
 * Queue abstract class                                    *
************************************************************/

#ifndef HELLOCPPLAB1_QUEUE_H
#define HELLOCPPLAB1_QUEUE_H

class Queue{
public:
    virtual void clear() = 0;
    virtual void enqueue(int value) = 0;
    virtual int dequeue() = 0;
    virtual int front ()  = 0;
    virtual bool isEmpty() const = 0;
};

#endif //HELLOCPPLAB1_QUEUE_H
