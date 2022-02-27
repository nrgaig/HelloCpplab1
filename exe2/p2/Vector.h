/* Created by Maor Frost 206370231 and Itay Oren 318648482
 * cpp lab - Meir Litman
 * exercise 2 task 2
 * class header represent a vector
 */

#ifndef HELLOCPPLAB1_VECTOR_H
#define HELLOCPPLAB1_VECTOR_H


class Vector {


public:

    Vector(int temp = 2);

    Vector(Vector const &copy);

    ~Vector();

    int getCapacity() const;

    int getSize() const;

    void print();

    void assign(Vector vec);

    bool isEqual(Vector vec);

    int &at(int index);

    int scalmul(Vector vec);

    Vector strnewcat(Vector vec);

    void clear();

    void delLast();

    void insert(int val);

private:
    int *data; // pointer array
    int capacity; // max size of array
    int size; // num of values in array
    bool isPowerOfTwo(int n);
    int newPowerOfTwo(int num);
};


#endif //HELLOCPPLAB1_VECTOR_H
