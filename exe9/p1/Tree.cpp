//
// Created by itayo on 19/05/2022.
//

#include "Tree.h"


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

template<class T>
void Tree<T>::reflect() {
}

template<class T>
void Tree<T>::breadthScan() {

}



