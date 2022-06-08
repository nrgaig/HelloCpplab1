//
// Created by itayo on 08/06/2022.
//

#include "Family.h"
#include <cstring>
#include <exception>
using namespace std;


class myEx1 : public exception{
    virtual const char* what() const throw(){
        return "bad thing";
    }
} type1;

Family::Family() {
    familyId = 0;
    strcpy(familyName,"");
    numOfFamilyMembers = 0;
    phoneNumber = 0;
    activityList = 0;
}

Family::Family(int familyId, char family_Name[21], int numOfFamilyMembers, int phoneNumber,short activityList) : familyId(
        familyId), numOfFamilyMembers(numOfFamilyMembers), phoneNumber(phoneNumber), activityList(0) {
    strcpy(familyName,family_Name);
}

int Family::getFamilyId() const {
    return familyId;
}

void Family::setFamilyId(int familyId) {
    Family::familyId = familyId;
}

const char *Family::getFamilyName() const {
    return familyName;
}

int Family::getNumOfFamilyMembers() const {
    return numOfFamilyMembers;
}

void Family::setNumOfFamilyMembers(int numOfFamilyMembers) {
    Family::numOfFamilyMembers = numOfFamilyMembers;
}

int Family::getPhoneNumber() const {
    return phoneNumber;
}

void Family::setPhoneNumber(int phoneNumber) {
    Family::phoneNumber = phoneNumber;
}

short Family::getActivityList() const {
    return activityList;
}

void Family::setActivityList(short activityList) {
    Family::activityList = activityList;
}




