/***********************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482 *
 * cpp lab - Meir Litman                                   *
 * exercise 5 task 1                                       *
 *    *
************************************************************/

#include "List.h"

//------------------------------------------------
//  class Link implementation
//------------------------------------------------
List::Link::Link(int val, Link *nxt) : value(val), next(nxt) {}


List::Link::Link(const Link &source) : value(source.value), next(source.next) {}


//--------------------------------------------
//  class List implementation
//--------------------------------------------
List::List() : head(nullptr) {
    // no further initialization
}

List::List(const List &l) {
    Link *src, *trg;
    if (l.head == nullptr)// if there are NO links in the list
        head = nullptr;// make new list head point to null
    else {// if there are SOME links in the list
        head = new Link((l.head)->value, nullptr);//create new link in the list and make head point to it
        src = l.head; //make src point to first link in l
        trg = head; //make trg point to this->head
        while (src->next != nullptr) { //while we not in the last link copy data (value, next) from l to this
            trg->next = new Link((src->next)->value, nullptr);//creating new link in 'this'
            src = src->next;
            trg = trg->next;
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
            return true;
    // not found
    return false;
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

ostream &operator<<(ostream &os, const List &ms) {
    if (ms.head != nullptr){// if there are SOME links in the list
        List::Link *lst;

        lst = ms.head; //make lst point to this->head
        while (lst->next != nullptr) { //while we not in the last link stream values to os
            os << lst->value << " ";
        }
    }
    return os;
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
            src = src->next;
            trg = trg->next;
        }
    }
    return *this;
}

istream &operator>>(istream &os, const List &ms) {
    return <#initializer#>;
}


