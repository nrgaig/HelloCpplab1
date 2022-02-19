//  Created by Maor Frost 206370231 Itay Oren 318648482
//  cpp lab - Meir Litman
//  exercise 1 task 2
//
//
#include <iostream>
#include "Worker.h"
using namespace std;

int main() {
    int input;
    char name[21];
    //asking from user to enter details:
    Worker lowestWork, highestWork, tempWorker;
    cout<< "enter details, to end enter 0:" << endl;

    while(input!=0)//untill 0 is entered do:
    {
        cin>>input;
        if(input==0)// if enter 0 is entered finnish the loop
            continue;

        tempWorker.setID(input);//if something else is entered it is the Worker id
        cin.get();//avoiding empty string
        cin.getline(name,20);//inputing string from user
        tempWorker.setName(name);
        cin>>input;//input hours
        tempWorker.setHours(input);
        cin>>input;
        tempWorker.setSalary(input);
        cin>>input;
        tempWorker.setIncome(input);

    }
}