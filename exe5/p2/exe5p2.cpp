/***********************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482 *
 * cpp lab - Meir Litman                                   *
 * exercise 5 task 2                                       *
 * main program we requested to use from exercise author   *
************************************************************/

#include <iostream>
#include "List.h"

using namespace std;

// getting two lists and merge them into one. return new merged list.
List merge(const List &lst1, const List &lst2) {
    List newList, temp1 = lst1, temp2 = lst2;// create new list, temporary lists to play with them and insert to new list

    while (!temp2.isEmpty()) { //running on lst2 values and insert into new list
        newList.insert(temp2.firstElement());
        temp2.removeFirst();
    }
    while (!temp1.isEmpty()) {//running on lst1 values and insert into new list
        newList.insert(temp1.firstElement());
        temp1.removeFirst();
    }
    return newList;
}

// reverse the list
void reverse(List &lst) {
    List temp = lst;  //create temporary list to play with it
    lst.clear();     //clear the list
    while (!temp.isEmpty()) { //running on temp values and insert into source list
        lst.add(temp.firstElement()); //add to the head of the list
        temp.removeFirst(); //remove the first element
    }
}

//delete duplicate nodes from lst
void makeSet(List &lst) {
    List newList, tmp = lst;// creating new empty list and temp list to play with it
    reverse(tmp);        // reverse temp to insert reversely
    newList.add(tmp.firstElement()); // adding the first element to newList
    tmp.removeFirst();      //remove the first element from tmp as we saved it in newList

    while (!tmp.isEmpty())  //running on tmp until tmp empty
    {
        if (tmp.firstElement() == newList.firstElement())// if first element is duplicate remove it
            tmp.removeFirst();
        newList.add(tmp.firstElement());// and so... adding the first element to newList
        tmp.removeFirst();// and so... remove the first element from tmp as we saved it in newList
    }
    lst = newList; //assigning newList into our lst
}

//main function
int main() {
    List lst1, lst2, mergedList;

    cout << "enter sorted values for the first list:" << endl;
    cin >> lst1;
    cout << "enter sorted values for the second list:" << endl;
    cin >> lst2;

    mergedList = merge(lst1, lst2);
    cout << "the new merged list: " << mergedList << endl;

    makeSet(mergedList);
    cout << "the new merged set: " << mergedList << endl;

    reverse(mergedList);
    cout << "the new merged reverse: " << mergedList << endl;


    return 0;
}
