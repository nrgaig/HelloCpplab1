//
// Created by itayo on 19/05/2022.
//

#ifndef HELLOCPPLAB1_SEARCHTREE_H
#define HELLOCPPLAB1_SEARCHTREE_H


#include "Tree.h"
#include <iostream>

using namespace std;

template<class T>
class SearchTree : public Tree<T> {

public:
    void add(T value);

    bool search(T value) {
        return search(Tree<T>::root, value);
    }
    void remove(T val);
    T successor(T val);
    void deleteDuplicates();

private:
    void add(typename Tree<T>::Node *current, T val);

    bool search(typename Tree<T>::Node *current, T val);
};


#endif //HELLOCPPLAB1_SEARCHTREE_H
