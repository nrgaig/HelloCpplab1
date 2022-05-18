//
// Created by itayo on 19/05/2022.
//

#ifndef HELLOCPPLAB1_TREE_H
#define HELLOCPPLAB1_TREE_H

#include  <iostream>

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


private:
    //private function for not give acsses to user
    void clear(Node *current);

    void preOrder(Node *current);

    void inOrder(Node *current);

    void postOrder(Node *current);

};


#endif //HELLOCPPLAB1_TREE_H
