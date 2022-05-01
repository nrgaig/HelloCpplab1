/********************************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482          *
 * cpp lab - Meir Litman                                            *
 * exercise 6 task 1                                                *
 * class represent a Full time Employee in "Learn to Fun" College   *
*********************************************************************/

#ifndef HELLOCPPLAB1_FULLTIME_H
#define HELLOCPPLAB1_FULLTIME_H

#include "Employee.cpp"


class FullTime : public Employee {
private:
    float salaryPerYear;

public:
    FullTime() : Employee(), salaryPerYear(0) {} // empty ctr

    FullTime(string workerName, int workerId, int workerSeniority, float new_salaryPerYear) :
    Employee(workerName,workerId,workerSeniority),salaryPerYear(new_salaryPerYear) {
        //ctr
        pay = salary();
    }

    FullTime(const FullTime &copy) : Employee(copy.getName(), copy.getId(), copy.getSeniority()),
                                     salaryPerYear(copy.salaryPerYear) {
        // copy ctr
        pay = salary();
    }


    float salary() { return salaryPerYear / 12; }//calculating salary per month

    friend istream &operator>>(istream &is, FullTime &ms) { //overloading >> operator
        cout << "Enter employee details:" << endl;
        string new_name;
        int new_id, new_seniority;
        float new_salary;
        is >> new_name >> new_id >> new_seniority  >> new_salary; //get inputs in constructing format

        if(new_seniority < 0 )// if new_seniority negative exception
            throw "ERROR";

        //set each property
        ms.name = new_name;
        ms.id = new_id;
        ms.seniority = new_seniority;
        ms.salaryPerYear = new_salary;
        ms.pay = ms.salary();
        return is;
    }

    friend ostream &operator<<(ostream &os, const FullTime &ms) { //overloading operator << ostream in particular format
        os << "Employee: " << ms.name << "\nEmployee ID: " << ms.id << "\nYears Seniority: " << ms.seniority <<"\nSalary per Month: "<<ms.pay<< endl;
        return os;
    }

    void setSalary(float newSalary) { salaryPerYear = newSalary; }

    float getSalaryPerYear() { return salaryPerYear; }

};


#endif //HELLOCPPLAB1_FULLTIME_H