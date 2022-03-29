/***********************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482 *
 * cpp lab - Meir Litman                                   *
 * exercise 5 task 1                                       *
 *   *
************************************************************/

#ifndef HELLOCPPLAB1_LIST_H
#define HELLOCPPLAB1_LIST_H


class List {
protected:
//--------------------------------------------
// inner class link
// a single element for the linked List
//--------------------------------------------
    class Link {
    public:
// constructor
        Link(int linkValue, Link *nextPtr);

        Link(const Link &amp;

        );
// data areas
        int value;
        Link *next;
    }; //end of class Link
public:
// constructors
    List();

    List(const List &amp;

    );

    ~List();

// operations
    void add(int value);

    int firstElement() const;

    bool search(const int &value) const;

    bool isEmpty() const;

    void removeFirst();

    void clear();

protected:
// data field
    Link *head;
};

};


#endif //HELLOCPPLAB1_LIST_H
