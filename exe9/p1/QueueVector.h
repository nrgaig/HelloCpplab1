//
// Created by itayo on 19/05/2022.
//

#ifndef HELLOCPPLAB1_QUEUEVECTOR_H
#define HELLOCPPLAB1_QUEUEVECTOR_H


#include "Queue.h"
template<class T>
class QueueVector : public Queue<T> {
public:
    QueueVector(int max);

    //QueueVector(const QueueVector&);
    void clear() override;

    T dequeue() override;

    void enqueue(T value) override;

    T front() override;

    bool isEmpty() const override;

private:
    T *data;
    int capacity;
    //int nextSlot;
    //int firstUse;
    int size;
};

template<class T>
QueueVector<T>::QueueVector(int _size) {
    capacity = _size ;
    size=0;
    data = new T[capacity];
    clear();
}
template<class T>
void QueueVector<T>::clear() {
    for (T i:data) {
        i=NULL;
    }
    size = 0;
}
template<class T>
T QueueVector<T>::dequeue() {
    T tmp=data[0];
    for (int i = 0; i <size; ++i) {
    data[i]=data[i+1];
    }
    data[size]=NULL;
    return tmp;
}
template<class T>
void QueueVector<T>::enqueue(T val) {
    if (size==capacity)
        throw "Vector is full";
    data[size]=val;
    size++;
}

template<class T>
T QueueVector<T>::front() {
    if (isEmpty())
        throw "Queue is empty\n";
    return data[0];
}

template<class T>
bool QueueVector<T>::isEmpty() const {
    return size==0;
}


#endif //HELLOCPPLAB1_QUEUEVECTOR_H
