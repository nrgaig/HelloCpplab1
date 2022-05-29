/***********************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482 *
 * cpp lab - Meir Litman                                   *
 * exercise 10 task 1                                      *
 * class implement private in army                         *
************************************************************/

#ifndef HELLOCPPLAB1_PRIVATESOLDIER_CPP
#define HELLOCPPLAB1_PRIVATESOLDIER_CPP

#include "Soldier.h"

using namespace std;

class PrivateSoldier : public Soldier {
public:
    PrivateSoldier(int id, const std::string &firstName, const std::string &lastName, int numOfOps, int *grades)
            : Soldier(id, firstName, lastName, numOfOps), grades(grades) {}

    bool medal() override {
        if (getNumOfOps() < 10)
            return false;
        int sum = 0;
        for (int i = 0; i < getNumOfOps(); i++) {
            sum += grades[i];
        }
        return (float) sum / (float) getNumOfOps() > 95;
    }
    void print() override {
        cout << soldierType() << endl;
        cout << "ID: " << getId() << endl;
        cout << "first name: " << getFirstName() << endl;
        cout << "last name: " << getLastName() << endl;
        cout << "num operations: " << getNumOfOps() << endl;

        if (grades != nullptr) {
            cout << "grades: ";
            for (int i = 0; i < getNumOfOps(); i++) {
                cout << this->grades[i] << " ";
            }
        }
        cout << endl;
    }
    string soldierType() override {
        return "private";
    }


protected:
    int *grades;
};

#endif //HELLOCPPLAB1_PRIVATESOLDIER_CPP