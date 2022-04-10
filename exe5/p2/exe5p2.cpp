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
List merge(const List& lst1, const  List& lst2){
    List newList, temp1 = lst1, temp2 = lst2;// create new list, temporary lists to play with them and insert to new list

    while(!temp2.isEmpty()){ //running on lst2 values and insert into new list
        newList.insert(temp2.firstElement());
        temp2.removeFirst();
    }
    while(!temp1.isEmpty()){//running on lst1 values and insert into new list
        newList.insert(temp1.firstElement());
        temp1.removeFirst();
    }
    return newList;
}

void makeSet(List& lst){

}
void reverse(List& lst){

}

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
