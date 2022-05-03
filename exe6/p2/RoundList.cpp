/***********************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482 *
 * cpp lab - Meir Litman                                   *
 * exercise 6 task 2                                       *
 * class implement Rounded List                            *
************************************************************/
#ifndef HELLOCPPLAB1_ROUNDLIST_H
#define HELLOCPPLAB1_ROUNDLIST_H

#include "List.h"

class RoundList : public List {


public:
    RoundList() : List() {}  // empty ctor
    ~RoundList() { clear(); }  // dtor


    void addToEnd(int val) {//Add a new value to the end  of a Round List
        if (head == nullptr) { //if the list is empty
            head = new Link(val, nullptr); //create a new head
            head->next = head;  //make the head point to itself
        } else { //if the list is not empty
            Link *temp = head->next; //create a temp pointer to the head
            head->next = new Link(val, temp); //make the head point to a new link
            head = head->next; //make the head point to the new link
        }
    }

    void add(int val) override {
        //Add a new value to the front of a Linked List
        if (head == nullptr) { //if the list is empty
            head = new Link(val, nullptr); //create a new head
            head->next = head;  //make the head point to itself
            if (head == nullptr) { //if the list is empty
                throw "failed in memory allocation";    //throw exception
            }
        } else { //if the list is not empty
            Link *newLink = new Link(val, head->next); //create a new link
            head->next = newLink; //make the head point to the new link
        }
    }

    void removeFirst() override {
        //Remove the first element of a Linked List
        if (head == nullptr)
            throw "list is empty";
        else {
            if (head->next == head) {
                delete head;
                head = nullptr;
            } else {
                Link *temp = head->next->next;
                delete head->next;
                head->next = temp;
            }
        }
    }

    void remove(int key) override {//removing the first element with the value key todo complete

        if (head->value == key) {// handling deletion for first element
            removeFromEnd();
            //head = head->next; // make head point to the next element
            return;
        }

        List::Link *p = head, *del; // p is the pointer to the element before the element we want to delete
        while (p->next != head && p->next->value !=
                                  key) { // while we not in the last link and the next element is not the one we want to delete
            p = p->next; // make p point to the next element
        }
        if (p->next == head)
            throw "value not found";

        p->next = p->next->next; // make p point to the next element


    }

    void removeFromEnd() { // as the name say
        // make sure there is a first element
        if (isEmpty())
            throw "the List is empty, no Elements to remove";
        // save pointer to the removed node
        Link *p = head;
        while (head->next != p)// reassign the first node
            head = head->next;

        head->next = p->next; //detach p
        p->next = nullptr;
        // recover memory used by the first element
        delete p;
    }

    int search(int n) {// search the link in index n in our list and return its value
        if (head == nullptr)// if list is empty return -1
            return -1;

        Link *p = head;
        for (int i = 0; i <= n; ++i) {//running on our RoundList links n times
            p = p->next;
        }
        return p->value; //return the value of p (link in index n)
    }

    void clear() override {
        //Clear a Linked List
        if (head == nullptr)
            return;
        Link *p = head;
        while (p->next != head) {
            p = p->next;
            delete p->next;
        }
        delete p;
        head = nullptr;
    }

    RoundList &operator=(const RoundList &l) {//copy assignment method for operator =
        Link *src;
        if (l.head == nullptr)// if there are NO links in the list
            head = nullptr;// make new list head point to null
        else {// if there are SOME links in the list
            head = new Link((l.head)->value, nullptr);//create new link in the list and make head point to it
            src = l.head->next; //make src point to first link in l
            while (src != l.head) { //while we not in the last link copy data (value, next) from l to this
                head->next = new Link(src->value, head->next);//creating new link in 'this'
                head = head->next;//pointing head to new head link
                src = src->next; //moving src to next link
            }
        }
        return *this;
    }

    friend istream &
    operator>>(istream &is, RoundList &ms) { //overloading >> operator - adding new values in not ascended order
        int val; // value to be read
        is >> val; // read the value
        ms.head = new List::Link(val, nullptr); // create a new link
        List::Link *lst = ms.head; // make lst point to the new link
        is >> val; // read the next value
        while (val < lst->value) { // while the value is less than the previous value
            //todo: check if it correct
            ms.addToEnd(val); // adding value to end of list
            is >> val; // read the next value
        }
        return is;
    }

    friend ostream &
    operator<<(ostream &os, const RoundList &ms) { //overloading operator << printing values of link in our list
        if (ms.head != nullptr) {// if there are SOME links in the list
            List::Link *lst;
            lst = ms.head->next; //make lst point to this->head->next
            while (lst != ms.head) { //while we not in the last link stream values to os
                os << lst->value << " "; //stream value to os
                lst = lst->next; //make lst point to next link
            }
            os << lst->value; //stream value to os
        }
        return os;
    }
};


#endif //HELLOCPPLAB1_ROUNDLIST_H
