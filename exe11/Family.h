//
// Created by itayo on 08/06/2022.
//

#ifndef HELLOCPPLAB1_FAMILY_H
#define HELLOCPPLAB1_FAMILY_H


class Family {

public:
    Family();
    Family(int familyId, char family_Name[21], int numOfFamilyMembers, int phoneNumber, short activityList);

    int getFamilyId() const;

    void setFamilyId(int familyId);

    const char *getFamilyName() const;

    int getNumOfFamilyMembers() const;

    void setNumOfFamilyMembers(int numOfFamilyMembers);

    int getPhoneNumber() const;

    void setPhoneNumber(int phoneNumber);

    short getActivityList() const;

    void setActivityList(short activityList);

    void setFamilyName(char string[21]);

protected:
    int familyId;
    char familyName[21]{};
    int numOfFamilyMembers;
    int phoneNumber;
    short activityList;


};


#endif //HELLOCPPLAB1_FAMILY_H
