/* Created by Maor Frost 206370231 and Itay Oren 318648482
 * cpp lab - Meir Litman
 * exercise 1 task 2
 * class represents Worker in "Latet Mehalev" association
 */
#include "Worker.h"
#include <cstring>

using namespace std;


Worker::Worker() {

}


void Worker::setID(int workerId) {
    id = workerId;
}

int Worker::getID() {
    return id;
}

void Worker::setName(char workerName[]) {
    strcpy(name, workerName);//copy string from workerName to this->name
}

char *Worker::getName() {
    return name;
}

void Worker::setSalary(float workerSalary) {
    salary = workerSalary;
}

float Worker::getSalary() {
    return salary;
}

void Worker::setHours(int workerHours) {
    hours = workerHours;
}

int Worker::getHours() {
    return hours;
}

void Worker::setIncome(float workerIncome) {
    income = workerIncome;
}

float Worker::getIncome() {
    return income;
}

// calculate worker salary value
float Worker::salaryCalc() {

    /*
     * for every income level return the base salary + the additional bonus
     * the bonus is sum of the levels + the remainder
     */

    float baseSalary = hours * salary;

    int const LEVEL1 = 100, LEVEL2 = 150, LEVEL3 = 400, LEVEL4 = 300;

    if (income <= 1000) {//if salary is below 1000
        return baseSalary + income * 0.1;
    }
    else if (income <= 2000) {//if salary is between 1000 and 2000
        return baseSalary + LEVEL1 + (income - 1000) * 0.15;
    }
    else if (income <= 4000) {//if salary is between 2000 and 4000
        return baseSalary + LEVEL1 + LEVEL2 + (income - 2000) * 0.2;
    }
    else if (income <= 5000) {//if salary is between 4000 and 5000
        return baseSalary + LEVEL1 + LEVEL2 + LEVEL3 + (income - 4000) * 0.3;
    }
    //if salary is GREATER than 5000
    return baseSalary + LEVEL1 + LEVEL2 + LEVEL3 + LEVEL4 + (income - 5000) * 0.4;
}
