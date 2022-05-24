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
    : Soldier(id,firstName,lastName,numOfOps),grades(grades) {}

private:
    int * grades;

};


#endif //HELLOCPPLAB1_PRIVATESOLDIER_CPP