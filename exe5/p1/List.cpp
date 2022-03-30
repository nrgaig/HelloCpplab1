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
    if (l.head == nullptr)
        head = nullptr;
    else {
        head = new Link((l.head)->value, nullptr);
        src = l.head;
        trg = head;
        while (src->next != nullptr) {
            trg->next = new Link((src->next)->value, nullptr);
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

    return os;
}
