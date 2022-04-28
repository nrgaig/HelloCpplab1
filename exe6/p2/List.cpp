/***********************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482 *
 * cpp lab - Meir Litman                                   *
 * exercise 6 task 2                                       *
 * List class from exe5                                    *
************************************************************/

#include "List.h"

//------------------------------------------------
//  class Link implementation
//------------------------------------------------
List::Link::Link(int val, Link *nxt) : value(val), next(nxt) {} //constructor


List::Link::Link(const Link &source) : value(source.value), next(source.next) {} //copy constructor


//--------------------------------------------
//  class List implementation
//--------------------------------------------
List::List() : head(nullptr) { } //constructor
// no further initialization

List::List(const List &l) { //copy constructor
    Link *src, *trg;
    if (l.head == nullptr)// if there are NO links in the list
        head = nullptr;// make new list head point to null
    else {// if there are SOME links in the list
        head = new Link((l.head)->value, nullptr);//create new link in the list and make head point to it
        src = l.head; //make src point to first link in l
        trg = head; //make trg point to this->head
        while (src->next != nullptr) { //while we not in the last link copy data (value, next) from l to this
            trg->next = new Link((src->next)->value, nullptr);//creating new link in 'this'
            src = src->next; //make src point to next link in l
            trg = trg->next; //make trg point to next link in 'this'
        }
    }
}


List::~List() {
    clear();
}


void List::clear() {
    // empty all elements from the List
    Link *theNext;
    for (Link *p = head; p != nullptr; p = theNext) {
        // delete the element pointed to by p
        theNext = p->next;
        p->next = nullptr;
        delete p;
    }
    // mark that the List contains no elements
    head = nullptr;
}

bool List::isEmpty() const {
    // test to see if the List is empty
    // List is empty if the pointer to the head
    // Link is null
    return head == nullptr;
}

void List::add(int val) {
    //Add a new value to the front of a Linked List
    head = new Link(val, head);
    if (head == nullptr)
        throw "failed in memory allocation";
}

int List::firstElement() const {
// return first value in List
    if (isEmpty())
        throw "the List is empty, no first Element";
    return head->value;
}

bool List::search(const int &val) const {
    // loop to test each element
    for (Link *p = head; p != nullptr; p = p->next)
        if (val == p->value)
            return !false; // it's fanny because it's true
    // not found
    return false;
}

void List::insert(int key) { //insert a new value to the list
    List::Link *p = head, *newLink; //p is the pointer to the head of the list
    if (p==nullptr||p->value < key) { //if the list is empty or the first element is smaller than the key
        p = new List::Link(key, head); //create a new link with the key and the head
        if (!p)
            throw "failed in memory allocation";
        head = p; //make the head point to the new link
        return;
    }

    while (p->next != nullptr && p->next->value > key) //while the next element is not null and the next element is bigger than the key
        p = p->next; //move to the next element

    newLink = new List::Link(key, p->next); //create a new link with the key and the next element
    if (!newLink)
        throw "failed in memory allocation";

    p->next = newLink;  //make the next element point to the new link
}

void List::remove(int key) {//removing the first element with the value key

    if (head->value == key){// handling deletion for first element
        head = head->next; // make head point to the next element
        return;
    }
    List::Link *p = head, *del; // p is the pointer to the element before the element we want to delete
    while (p->next != nullptr && p->next->value != key) { // while we not in the last link and the next element is not the one we want to delete
        p = p->next; // make p point to the next element
    }
    if (p->next == nullptr)
        throw "value not found";

    p->next = p->next->next; // make p point to the next element


}

void List::removeFirst() {
    // make sure there is a first element
    if (isEmpty())
        throw "the List is empty, no Elements to remove";
    // save pointer to the removed node
    Link *p = head;
    // reassign the first node
    head = p->next;
    p->next = nullptr;
    // recover memory used by the first element
    delete p;
}

List &List::operator=(const List &l) {//copy assignment method for operator =
    Link *src, *trg;
    if (l.head == nullptr)// if there are NO links in the list
        head = nullptr;// make new list head point to null
    else {// if there are SOME links in the list
        head = new Link((l.head)->value, nullptr);//create new link in the list and make head point to it
        src = l.head; //make src point to first link in l
        trg = head; //make trg point to this->head
        while (src->next != nullptr) { //while we not in the last link copy data (value, next) from l to this
            trg->next = new Link((src->next)->value, nullptr);//creating new link in 'this'
            src = src->next; //moving src to next link
            trg = trg->next; //moving trg to next link
        }
    }
    return *this;
}

istream &operator>>(istream &is, List &ms) { //overloading >> operator

    int val; // value to be read
    is >> val; // read the value
    ms.head = new List::Link(val, nullptr); // create a new link
    List::Link *lst = ms.head; // make lst point to the new link
    is >> val; // read the next value
    while (val < lst->value) { // while the value is less than the previous value
        lst->next = new List::Link(val, nullptr); // create a new link
        if (lst->next == nullptr) // if the new link is not created
            throw "failed in memory allocation"; // throw an exception
        lst = lst->next; // make lst point to the new link
        lst->value = val; // assign the value to the new link
        is >> val; // read the next value
    }
    return is;
}

ostream &operator<<(ostream &os, const List &ms) { //overloading operator <<
    List::Link *ptr = ms.head; //make ptr point to head
    if (ms.head != nullptr) {// if there are SOME links in the list
        List::Link *lst;
        lst = ptr; //make lst point to this->head
        while (lst->next != nullptr) { //while we not in the last link stream values to os
            os << lst->value << " "; //stream value to os
            lst = lst->next; //make lst point to next link
        }
        os << lst->value; //stream value to os
    }
    return os;
}