//  Created by Maor Frost 206370231 Itay Oren 318648482
//  cpp lab - Meir Litman
//  exercise 1 task 2
//
//
#include <iostream>
#include "Worker.h"
#include <cstring>

using namespace std;


Worker::Worker()
{

}


void Worker::setID(int workerId)
{
    id = workerId;
}

int Worker::getID()
{
    return id;
}

void Worker::setName(char workerName[])
{
    strcpy(name, workerName);
}

char *Worker::getName()
{
    return name;
}

void Worker::setSalary(float workerSalary)
{
    salary = workerSalary;
}

float Worker::getSalary()
{
    return salary;
}

void Worker::setHours(int workerHours)
{
    hours = workerHours;
}

int Worker::getHours()
{
    return hours;
}

void Worker::setIncome(float workerIncome)
{
    income = workerIncome;
}

float Worker::getIncome()
{
    return income;
}

// calculate worker salary value
float Worker::salaryCalc()
{
    float bonus;
    float finalSalary = hours * salary;

    if (salary <= 1000)
    {//if salary is below 1000
        return finalSalary + income * 0.1;
    } else if (salary <= 2000)
    {//if salary is between 1000 and 2000
        return finalSalary + 100 + (income - 1000) * 0.15;
    } else if (salary <= 4000)
    {//if salary is between 2000 and 4000
        return finalSalary + 100 + 300 + (income - 2000) * 0.2;
    } else if (salary <= 5000)
    {//if salary is between 4000 and 5000
        return finalSalary + 100 + 300 + 400 + (income - 4000) * 0.3;
    }
    //if salary is GREATER than 5000
    return finalSalary + 100 + 300 + 400 + 1500 + (income - 5000) * 0.4;
}
