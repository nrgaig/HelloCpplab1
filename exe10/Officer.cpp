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


private:
    int sociometry;
};


#endif //HELLOCPPLAB1_OFFICER_CPP
