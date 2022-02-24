/* Created by Maor Frost 206370231 and Itay Oren 318648482
 * cpp lab - Meir Litman
 * exercise 1 task 2
 * program to manage workers in the association
 * printing the worker with highest salary and the worker with the lowest income
 */
#include <iostream>
#include "Worker.h"

using namespace std;

int main() {
    float input = 1;
    char name[21];
    // flag for checking input correctness
    // //first to ensure that in the first iteration the details of the
    // will enter to both objects
    bool flag = true, first = true;

    Worker lowestWorker, highestWorker, tempWorker;

    //asking from user to enter details:
    cout << "enter details, to end enter 0:" << endl;

    while (input != 0)//until 0 is entered do:
    {
        flag = true;
        cin >> input;
        if (input == 0)// if enter 0 is entered finnish the loop
            break;
        if (input < 0)//if input is negative its illegal
            flag = false;
        tempWorker.setID(input);//if something else is entered it is the Worker id

        cin >> name;// getting worker's name
        tempWorker.setName(name);

        cin >> input;//getting worker's salary
        if (input < 0)//if input is negative its illegal
            flag = false;
        tempWorker.setSalary(input);

        cin >> input;//getting worker's hours
        if (input < 0)
            flag = false;
        tempWorker.setHours(input);

        cin >> input;//getting worker's income
        if (input < 0)//if input is negative its illegal
            flag = false;
        tempWorker.setIncome(input);

        if (flag) { // if all input is correct and legal

            // checking if the income is the lowset
            if (tempWorker.getIncome() < lowestWorker.getIncome() || first) {
                //if true set temp worker as lowest worker
                lowestWorker.setID(tempWorker.getID());
                lowestWorker.setName(tempWorker.getName());
                lowestWorker.setIncome(tempWorker.getIncome());
            }
            // checking if the salary is the highest
            if (tempWorker.salaryCalc() > highestWorker.salaryCalc() || first) {
                //if true set temp worker as highest worker
                highestWorker.setID(tempWorker.getID());
                highestWorker.setName(tempWorker.getName());
                highestWorker.setIncome(tempWorker.getIncome());
                highestWorker.setHours(tempWorker.getHours());
                highestWorker.setSalary(tempWorker.getSalary());
                first = false; // after the first iteration first becume false
            }
        }
        else//if some input is incorrect or illegal print error and get inputs again
            cout << "ERROR" << endl;
    }
    //printing  the worker with highest salary and the worker with the lowest income
    cout << "minimum collected: " << lowestWorker.getID() << " " << lowestWorker.getName() << " " << lowestWorker.getIncome()
         << endl << "highest salary: " << highestWorker.getID() << " " << highestWorker.getName() << " "
         << highestWorker.salaryCalc();

}
/*
enter details, to end enter 0:
1
doron
35
120
6000
2
tal
50
55
1400
3
maor
45
-5
100
ERROR
4
itay
30
120
800
0
minimum collected: 4 itay 800
highest salary: 1 doron 5550
*/