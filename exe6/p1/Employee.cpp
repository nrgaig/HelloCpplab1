//
// Created by itayo on 25/04/2022.
//

#ifndef HELLOCPPLAB1_EMPLOYEE_CPP
#define HELLOCPPLAB1_EMPLOYEE_CPP

#include<iostream>
#include <string>

using namespace std;

class Employee {
protected:
    string name;
    int id;
    int seniority;
    float pay;
public:
    Employee() { // empty constructor
        name = "";
        id = 0;
        seniority = 0;
        pay = 0;
    }

    Employee(string workerName, int workerId, int workerSeniority) { // constructor
        name = workerName;
        id = workerId;
        seniority = workerSeniority;
        pay = 0;
    }

    Employee(const Employee &copy) {
        // copy constructor
        name = copy.name;
        id = copy.id;
        seniority = copy.seniority;
        pay = copy.pay;
    }

    float salaryAfterBonus() {// updating salary after bonus of Tishrei
        if (seniority <= 5)//if employee is senior less 5 years
            pay += 500;    // bonus  is 500
        if (seniority > 5) //if employee is senior 5 or more years
            pay *= 1.25;   // bonus is 0.25 pay
        return pay;
    }

    friend istream &operator>>(istream &is, Employee &ms) { //overloading >> operator
        cout<<"Enter employee details:"<<endl;
        string new_name;
        int new_id, new_seniority;
        float new_pay;
        is >> new_name >> new_id >> new_seniority >> new_pay; //get inputs in constructing format
        //set each property
        ms.name = new_name;
        ms.id = new_id;
        ms.seniority = new_seniority;
        ms.pay = new_pay;
        return is;
    }

    friend ostream &operator<<(ostream &os, const Employee &ms) { //overloading operator << ostream in particular format
        os << "Employee: " << ms.name << "\nEmployee ID: " << ms.id << "\nYears Seniority: " << ms.seniority << endl;
        return os;
    }

    const string &getName() const { return name; }

    void setName(const string &new_name) { Employee::name = new_name; }

    int getId() const { return id; }

    void setId(int new_id) { Employee::id = new_id; }

    int getSeniority() const { return seniority; }

    void setSeniority(int new_seniority) { Employee::seniority = new_seniority; }

    float getPay() const { return pay; }

    void setPay(float new_pay) { Employee::pay = new_pay; }

};

#endif //HELLOCPPLAB1_EMPLOYEE_CPP