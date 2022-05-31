//
// Created by itayo on 19/05/2022.
//

#ifndef HELLOCPPLAB1_TREE_H
#define HELLOCPPLAB1_TREE_H

#include  <iostream>
#include "Queue.h"
#include "QueueVector.h"
using namespace std;
//-----------------------------------
//  class Tree (Binary Trees)
// process nodes in Pre/In/Post  order
//-----------------------------------
template<class T>
class Tree {
protected:
    //--------------------------------------------------------
    //  inner class Node
    //      a single Node from a binary tree
    //--------------------------------------------------------
    class Node {
    public:
        Node *left;
        Node *right;
        T value;

        Node(T val) : value(val), left(nullptr) {}

        Node(T val, Node *l, Node *r) : value(val), left(l), right(r) {}
    };        //end of Node class

    //data member of tree
    Node *root;

public:
    Tree() { root = nullptr; }     // initialize tree
    ~Tree();

    int isEmpty() const;

    void clear() {
        clear(root);
        root = nullptr;
    }

    void preOrder() { preOrder(root); }

    void inOrder() { inOrder(root); }

    void postOrder() { postOrder(root); }

    virtual void process(T val) { std::cout << val << " "; }

    virtual void add(T val) = 0;

    virtual bool search(T val) = 0;

    virtual void remove(T val) = 0;

    int height();

    void reflect();

    void breadthScan();


private:
    //private function for not give acsses to user
    void clear(Node *current);

    void preOrder(Node *current);

    void inOrder(Node *current);

    void postOrder(Node *current);

};
//----------------------------------------------------------
//  class Tree implementation
//----------------------------------------------------------
template<class T>
Tree<T>::~Tree() // deallocate tree
{
    if (root != nullptr)
        clear(root);
}

template<class T>
void Tree<T>::clear(Node *current) {
    if (current) {    // Release memory associated with children
        if (current->left)
            clear(current->left);
        if (current->right)
            clear(current->right);
        delete current;
    }
}

template<class T>
int Tree<T>::isEmpty() const {
    return root == nullptr;
}

// preOrder processing of tree rooted at current
template<class T>
void Tree<T>::preOrder(Node *current) {    // visit Node, left child, right child
    if (current) {   // process current Node
        process(current->value);
        // then visit children
        preOrder(current->left);
        preOrder(current->right);
    }
}

// inOrder processing of tree rooted at current
template<class T>
void Tree<T>::inOrder(Node *current) {    // visit left child, Node, right child
    if (current) {
        inOrder(current->left);
        process(current->value);
        inOrder(current->right);
    }
}

// postOrder processing of tree rooted at current
template<class T>
void Tree<T>::postOrder(Node *current) {    // visit left child, right child, node
    if (current) {
        postOrder(current->left);
        postOrder(current->right);
        process(current->value);
    }
}
template<class T>
int Tree<T>::height() {
    if (root == nullptr)
        return 0;
    else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
}
// reflect the tree
template<class T>
void Tree<T>::reflect() {
    if (root == nullptr)
        return;
    else {
        Node *temp = root->left;
        root->left = root->right;
        root->right = temp;
        reflect(root->left);
        reflect(root->right);
    }
}

template<class T>
void Tree<T>::breadthScan() {
    if (root == nullptr)
        return;
    else {
        Queue *q = new QueueVector(height());
        q->enqueue(root);
        while (!q->isEmpty()) {
            Node *current = q->dequeue();
            process(current->value);
            if (current->left)
                q->enqueue(current->left);
            if (current->right)
                q->enqueue(current->right);
        }
    }
}

#endif //HELLOCPPLAB1_TREE_H
