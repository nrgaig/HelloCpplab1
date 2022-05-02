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
    //RoundList(const RoundList &l){} //ctor
    ~RoundList() { clear(); }  // dtor


    void addToEnd(int val) {//Add a new value to the end  of a Round List
        /* pseudo code:
         * newLink=creatLink()
         * newLink.setKey(val)
         * newLink.next()=head.next()
         * head.next() = newLink
         * head=head.next()
         *
         * at the start, head->next point to the first element.
         * now we creat a new link that points to the first element and hold the value.
         * after that make head->next (the former last element) point to the new last element.
         * and finally make head point to the new last element.
        */
        head->next = new Link(val, head->next);
        head = head->next;
    }

    void add(int val) override {
        //Add a new value to the front of a Linked List
        if (head == nullptr) {
            head = new Link(val, head);
            if (head == nullptr)
                throw "failed in memory allocation";
        }
        else {
            head->next = new Link(val, head);
            if (head == nullptr)
                throw "failed in memory allocation";
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
        while(head->next!=p)// reassign the first node
            head=head->next;

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

    friend istream &operator>>(istream &is, RoundList &ms) { //overloading >> operator - adding new values in not ascended order
        int val; // value to be read
        is >> val; // read the value
        ms.head = new List::Link(val, nullptr); // create a new link
        List::Link *lst = ms.head; // make lst point to the new link
        is >> val; // read the next value
        while (val < lst->value) { // while the value is less than the previous value
            //todo: check if it correct
            ms.addToEnd(val); // adding value to end of list
            is >> val; // read the next value


            //            lst->next = new List::Link(val, nullptr); // create a new link
            //            if (lst->next == nullptr) // if the new link is not created
            //                throw "failed in memory allocation"; // throw an exception
            //            lst = lst->next; // make lst point to the new link
            //            lst->value = val; // assign the value to the new link
            //            is >> val; // read the next value
        }
        return is;
    }

    friend ostream &operator<<(ostream &os, const RoundList &ms) { //overloading operator << printing values of link in our list
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


    // List::add(int key) not needed. replaced by: addToEnd(int val)
};


#endif //HELLOCPPLAB1_ROUNDLIST_H
