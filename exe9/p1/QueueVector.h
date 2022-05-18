//
// Created by itayo on 19/05/2022.
//

#ifndef HELLOCPPLAB1_QUEUEVECTOR_H
#define HELLOCPPLAB1_QUEUEVECTOR_H


#include "Queue.h"

class QueueVector : public Queue {
public:
    QueueVector(int max);

    //QueueVector(const QueueVector&);
    void clear() override;

    int dequeue() override;

    void enqueue(int value) override;

    int front() override;

    bool isEmpty() const override;

private:
    int *data;
    int capacity;
    int nextSlot;
    int firstUse;
};


#endif //HELLOCPPLAB1_QUEUEVECTOR_H
