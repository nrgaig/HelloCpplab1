/***********************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482 *
 * cpp lab - Meir Litman                                   *
 * exercise 5 task 2                                       *
 * main program we requested to use from exercise author   *
************************************************************/

#include <iostream>
#include "List.h"

using namespace std;
//הגדרת ומימוש הפונקציות

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
