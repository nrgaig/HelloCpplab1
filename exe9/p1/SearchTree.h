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
template<class T>
void SearchTree<T>::add(T val) {
    // add value to binary search tree
    if (!Tree<T>::root) {
        Tree<T>::root = new typename Tree<T>::Node(val);
        return;
    }
    add(Tree<T>::root, val);
}

template<class T>
void SearchTree<T>::add(typename Tree<T>::Node *current, T val) {
    if (current->value < val)

        if (!current->right) {
            current->right->parent=current;
            current->right = new typename Tree<T>::Node(val);
            return;
        } else add(current->right, val);
    else if (!current->left) {
        current->left->parent=current;
        current->left = new typename Tree<T>::Node(val);
        return;
    } else add(current->left, val);
}

template<class T>
bool SearchTree<T>::search(typename Tree<T>::Node *current, T val) {
    // see if argument value occurs in tree
    if (!current)
        return false;    // not found
    if (current->value == val)
        return true;
    if (current->value < val)
        return search(current->right, val);
    else
        return search(current->left, val);
}

template<class T>
void SearchTree<T>::remove(T val) {
    if (!Tree<T>::root)
        return;
    remove(Tree<T>::root, val);
    if (val == Tree<T>::root->value) {
        typename Tree<T>::Node *temp = Tree<T>::root;
        Tree<T>::root = Tree<T>::root->right;
        delete temp;
    }
}

template<class T>
T SearchTree<T>::successor(T val) {
    if (!Tree<T>::root)
        throw "no successor";
    typename Tree<T>::Node *current = Tree<T>::root;
    while (current) {
        if (current->value == val) {
            if (current->right) {
                current = current->right;
                while (current->left)
                    current = current->left;
                return current->value;
            } else {
                throw "no successor";
            }
        } else if (current->value < val)
            current = current->right;
        else
            current = current->left;
    }
    throw "no successor";
}

template<class T>
void SearchTree<T>::deleteDuplicates() {
    if (!Tree<T>::root)
        return;
    typename Tree<T>::Node *current = Tree<T>::root;
    while (current){
        if (successor(current->value) == current->value) {
            typename Tree<T>::Node *temp = current;
            current = current->right;
            delete temp;
        }
    }

}

#endif //HELLOCPPLAB1_SEARCHTREE_H
