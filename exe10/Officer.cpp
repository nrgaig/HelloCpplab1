/***********************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482 *
 * cpp lab - Meir Litman                                   *
 * exercise 10 task 1                                      *
 * class implement Officer in army                         *
************************************************************/
#ifndef HELLOCPPLAB1_OFFICER_CPP
#define HELLOCPPLAB1_OFFICER_CPP

#include "Soldier.h"

using namespace std;

class Officer : public Soldier {
public:
    Officer(int id, const string &firstName, const string &lastName, int numOfOps, int sociometry)
    : Soldier(id, firstName, lastName, numOfOps), sociometry(sociometry) {}

    bool medal() override { // boolean method return if soldier eligible for commendation
        if (getNumOfOps() < 2)
            return false;
        return sociometry >= 92;
    }

    void print() override {
        cout << soldierType() << endl;
        cout << "ID: " << getId() << endl;
        cout << "first name: " << getFirstName() << endl;
        cout << "last name: " << getLastName() << endl;
        cout << "num of operations: " << getNumOfOps() << endl;
        cout << "sociometry: " << sociometry << endl;
    }
    string soldierType() override {
        return "officer";
    }
    int getSociometric() const {
        return sociometry;
    }


private:
    int sociometry;
};


#endif //HELLOCPPLAB1_OFFICER_CPP
