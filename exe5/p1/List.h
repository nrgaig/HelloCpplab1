/***********************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482 *
 * cpp lab - Meir Litman                                   *
 * exercise 5 task 1                                       *
 *   *
************************************************************/

#ifndef HELLOCPPLAB1_LIST_H
#define HELLOCPPLAB1_LIST_H

#include <iostream>

using namespace std;


class List {
public:
//--------------------------------------------
// inner class link
// a single element for the linked List
//--------------------------------------------
    class Link {
    public:
// constructor
        Link(int linkValue, Link *nextPtr);

        Link(const Link &);

// data areas
        int value;
        Link *next;
    }; //end of class Link
// constructors
    List();

    List(const List &);

    ~List();

// operations
    void add(int value);

    int firstElement() const;

    bool search(const int &value) const;

    bool isEmpty() const;

    void removeFirst();

    void clear();

    friend ostream &operator<<(ostream &os, const List &ms);
    friend istream &operator>>(istream& os,  List& ms);

    void insert(int key);

    void remove (int key);

    List &operator=(const List &ms);//copy assignment method for operator =

private:
// data field
    Link *head;
};


#endif //HELLOCPPLAB1_LIST_H
