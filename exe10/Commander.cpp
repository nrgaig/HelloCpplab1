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

private:
    bool isBelligerent;

};


#endif //HELLOCPPLAB1_COMMANDER_CPP
