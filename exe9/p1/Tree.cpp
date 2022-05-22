//
// Created by itayo on 19/05/2022.
//

#include "Tree.h"
#include "Queue.h"
#include "QueueVector.h"



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

//A method that scans the tree nodes laterally and prints the node values level by level (starting from the root) from left to right. This method will use an queue data structure (the queue data structure should be included in its generic definition as well as the class that inherits a queue that implements a queue by a vector or list)template<class T>template<class T>
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



