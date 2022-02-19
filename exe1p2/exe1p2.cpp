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
    bool flag = true, first = true;
    //asking from user to enter details:
    Worker lowestWork, highestWork, tempWorker;
    cout << "enter details, to end enter 0:" << endl;

    /*
     * TO DO:
     * make shure that the first worker enter to both high and low in the first iteration
     *
     */

    while (input != 0)//until 0 is entered do:
    {
        cin >> input;
        if (input == 0)// if enter 0 is entered finnish the loop
            break;
        if (input < 0)
            flag = false;
        tempWorker.setID(input);//if something else is entered it is the Worker id

        cin.get();//avoiding empty string
        cin.getline(name, 20);//inputting string from user
        tempWorker.setName(name);

        cin >> input;//input hours
        if (input < 0)
            flag = false;
        tempWorker.setHours(input);

        cin >> input;
        if (input < 0)
            flag = false;
        tempWorker.setSalary(input);

        cin >> input;
        if (input < 0)
            flag = false;
        tempWorker.setIncome(input);

        if (flag) {
            if (tempWorker.getIncome() < lowestWork.getIncome() || first) {
                lowestWork.setID(tempWorker.getID());
                lowestWork.setName(tempWorker.getName());
                lowestWork.setIncome(tempWorker.getIncome());
            }
            if (tempWorker.salaryCalc() > highestWork.salaryCalc() || first) {
                highestWork.setID(tempWorker.getID());
                highestWork.setName(tempWorker.getName());
                highestWork.setIncome(tempWorker.getIncome());
                highestWork.setHours(tempWorker.getHours());
                highestWork.setSalary(tempWorker.getIncome());
            }
            first = false;
        }
        else
            cout << "ERROR";

    }
    cout << "minimum collected: " << lowestWork.getID() << " " << lowestWork.getName() << " " << lowestWork.getIncome()
         << endl << "highest salary: " << highestWork.getID() << " " << highestWork.getName() << " " << highestWork.salaryCalc();
}