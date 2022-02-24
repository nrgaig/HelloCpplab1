/* Created by Maor Frost 206370231 and Itay Oren 318648482
 * cpp lab - Meir Litman
 * exercise 1 task 2
 * class Header represents Worker in "Latet Mehalev" association
 */

#ifndef CPPLAB2_WORKER_H
#define CPPLAB2_WORKER_H


class Worker{
public:
    Worker();

    void setID(int id);

    int getID();

    void setName(char name[]);

    char *getName();

    void setSalary(float salary);

    float getSalary();

    void setHours(int hours);

    int getHours();

    void setIncome(float income);

    float getIncome();

    float salaryCalc();

private:
    int id;
    char name[21];
    float salary;
    int hours;
    float income;
};


#endif //CPPLAB2_WORKER_H
