//  Created by Maor Frost 206370231 Itay Oren 318648482
//  cpp lab - Meir Litman
//  exercise 1 task 2
//
//
#include <iostream>
#include "Worker.h"

using namespace std;

int main() {
    float input;
    char name[21];
    bool flag = true, first = true;
    //asking from user to enter details:
    Worker lowestWork, highestWork, tempWorker;
    cout << "enter details, to end enter 0:" << endl;

    while (input != 0)//until 0 is entered do:
    {
        flag = true;
        cin >> input;
        if (input == 0)// if enter 0 is entered finnish the loop
            break;
        if (input < 0)
            flag = false;
        tempWorker.setID(input);//if something else is entered it is the Worker id

        cin >> name;
        tempWorker.setName(name);

        cin >> input;
        if (input < 0)
            flag = false;
        tempWorker.setSalary(input);

        cin >> input;//input hours
        if (input < 0)
            flag = false;
        tempWorker.setHours(input);

        cin >> input;
        if (input < 0)
            flag = false;
        tempWorker.setIncome(input);

        if (!flag) {
            cout << "ERROR" << endl;
        }
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
                highestWork.setSalary(tempWorker.getSalary());
                first = false;
            }
            first = false;
    }
    cout << "minimum collected: " << lowestWork.getID() << " " << lowestWork.getName() << " " << lowestWork.getIncome()
         << endl << "highest salary: " << highestWork.getID() << " " << highestWork.getName() << " "
         << highestWork.salaryCalc();
}