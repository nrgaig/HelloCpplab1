/***********************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482 *
 * cpp lab - Meir Litman                                   *
 * exercise 10 task 1                                      *
 * class implement commander in army                       *
************************************************************/
#ifndef HELLOCPPLAB1_COMMANDER_CPP
#define HELLOCPPLAB1_COMMANDER_CPP

#include "PrivateSoldier.cpp"

using namespace std;

class Commander : public PrivateSoldier {
public:
    Commander(int id, const string &firstName, const string &lastName, int numOfOps, int *grades, bool isBelligerent)
            : PrivateSoldier(id, firstName, lastName, numOfOps, grades), isBelligerent(isBelligerent) {}
    bool medal() override {
        if (getNumOfOps() < 7)
            return false;
        if (!isBelligerent)
            return false;
        int sum = 0;
        for (int i = 0; i < getNumOfOps(); i++) {
            sum += grades[i];
        }
        return (float) sum / (float) getNumOfOps() > 90;
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
        cout << "combat: "; isBelligerent ? cout << "yes" : cout << "no"; cout << endl;
    }
    string soldierType() override {
        return "commander";
    }
    bool getIsBelligerent(){
        return isBelligerent;
    }

private:
    bool isBelligerent;

};


#endif //HELLOCPPLAB1_COMMANDER_CPP
