/***********************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482 *
 * cpp lab - Meir Litman                                   *
 * exercise 10 task 1                                      *
 * Abstract class represent generally a Soldier in army    *
************************************************************/

#ifndef HELLOCPPLAB1_SOLDIER_H
#define HELLOCPPLAB1_SOLDIER_H

#include <string>

using namespace std;

class Soldier {
public:
    Soldier(int _id, const string &_firstName, const string &_lastName, int _numOfOps) : id(_id), firstName(_firstName),
                                                                                         lastName(_lastName),
                                                                                         numOfOps(_numOfOps) {}

    virtual ~Soldier() {

    }

    virtual bool medal() = 0; // boolean method return if soldier eligible for commendation
    virtual void print() = 0; //printing soldier's details
    virtual string soldierType() = 0;

private:
    int id;
    string firstName;
    string lastName;
    int numOfOps;

};


#endif //HELLOCPPLAB1_SOLDIER_H
