//
// Created by itayo on 19/05/2022.
//

#include "SearchTree.h"

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
            current->right = new typename Tree<T>::Node(val);
            return;
        } else add(current->right, val);
    else if (!current->left) {
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
    Tree::Node *p
}


