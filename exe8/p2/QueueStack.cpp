/***********************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482 *
 * cpp lab - Meir Litman                                   *
 * exercise 8 task 2                                       *
 * class represent queue made from stack                   *
************************************************************/
#ifndef HELLOCPPLAB1_QUEUESTACK_H
#define HELLOCPPLAB1_QUEUESTACK_H

#include "Queue.h"
#include "StackVector.h"

class QueueStack : public Queue
{
protected:
    Stack* data;
public:
    QueueStack() : data(new StackVector{100}){}
    void clear() override{
        data->clear();
    }
    int dequeue() override {
        StackVector stk{100};
        int val;
        while (!data->isEmpty()){
            stk.push((data->pop()));
        }
        val=stk.pop();
        while (!stk.isEmpty()){
            data->push((stk.pop()));
        }

        return val;
    }
    void enqueue(int value) override{
        data->push(value);
    }
    int front() override{
        StackVector stk{100};
        int val;
        while (!data->isEmpty()){
            stk.push((data->pop()));
        }
        val=stk.top();
        while (!stk.isEmpty()){
            data->push((stk.pop()));
        }

        return val; // return front value
    }

    bool isEmpty() const override{ //return if our data (stack) is empty
        return data->isEmpty();
    }
};



#endif //HELLOCPPLAB1_QUEUESTACK_H