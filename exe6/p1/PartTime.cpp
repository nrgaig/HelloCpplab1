/********************************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482          *
 * cpp lab - Meir Litman                                            *
 * exercise 6 task 1                                                *
 * class represent a Part time Employee in "Learn to Fun" College   *
*********************************************************************/


#include "Employee.cpp"

#ifndef HELLOCPPLAB1_PARTTIME_H
#define HELLOCPPLAB1_PARTTIME_H


class PartTime : public Employee{
private:
    int	hoursOfWork;
    float payPerHour;
public:
    PartTime() : Employee(), hoursOfWork(0), payPerHour(0) {} // empty ctr

    PartTime(string workerName, int workerId, int workerSeniority, int new_hoursOfWork, float new_payPerHour) :
    Employee(workerName,workerId,workerSeniority),hoursOfWork(new_hoursOfWork),  payPerHour(new_payPerHour){
            //ctr
            pay = salary();
    }
    PartTime(const PartTime &copy) : Employee(copy.getName(), copy.getId(), copy.getSeniority()), hoursOfWork(copy.hoursOfWork),  payPerHour(copy.payPerHour) {
        // copy ctr
        pay = salary();
    }




    float salary() { return hoursOfWork*payPerHour;}//calculating salary per month



    friend istream &operator>>(istream &is, PartTime &ms) { //overloading >> operator
        cout << "Enter employee details:" << endl;
        string new_name;
        int new_id, new_seniority;
        float new_hours, new_pay;
        is >> new_name >> new_id >> new_seniority  >> new_hours>>new_pay; //get inputs in constructing format

        if(new_seniority < 0 || new_hours<0 )// if new_seniority or new_hours negative exception
            throw "ERROR";

        //set each property
        ms.name = new_name; //set name
        ms.id = new_id; //set id
        ms.seniority = new_seniority; //set seniority
        ms.hoursOfWork = new_hours;
        ms.payPerHour=new_pay;
        ms.pay = ms.salary();
        return is;
    }

    friend ostream &operator<<(ostream &os, const PartTime &ms) { //overloading operator << ostream in particular format
        os << "Employee: " << ms.name << "\nEmployee ID: " << ms.id << "\nYears Seniority: " << ms.seniority <<
        "\nHours: "<<ms.hoursOfWork<<"\nSalary per Month: "<<ms.pay<< endl;
        return os;
    }


};


#endif //HELLOCPPLAB1_PARTTIME_H