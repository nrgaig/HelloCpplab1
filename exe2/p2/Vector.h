//
// Created by itayo on 26/02/2022.
//

#ifndef HELLOCPPLAB1_VECTOR_H
#define HELLOCPPLAB1_VECTOR_H


class Vector {


public:

    Vector(int temp = 2);

    Vector(Vector const &copy);

    ~Vector();
    bool isPowerOfTwo(int n);

    int getCapacity() const;

    int getSize() const;

    void print();

    void assign(Vector vec);

    bool isEqual(Vector vec);

    int &at(int index);

    int scalmul(Vector vec);

    int *strnewcat(Vector vec);

    void clear();

    void delLast();

    void insert(int val);

private:
    int *data; // pointer array
    int capacity; // max size of array
    int size; // num of values in array
};


#endif //HELLOCPPLAB1_VECTOR_H
