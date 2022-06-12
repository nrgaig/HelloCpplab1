#include "Family.h"
#include <queue>
#include <iostream>
#include <fstream>
#include <exception>
#include <cstring>

using namespace std;

enum {
    EXIT, ADD, DEL, COUNT, UPDATE, WAITING, PRINT
};

class InvalidResponse : public exception {
    const char *what() const throw() { return "ERROR: Invalid response"; }
} invalidResponse;

class InvalidFamilyNumber : public exception {
    const char *what() const throw() { return "ERROR: Invalid family number"; }
} InvalidFamilyNum;

class FamilyInTheFile : public exception {
    const char *what() const throw() { return "ERROR: Family is already in the file"; }
} familyInTheFile;

class FamilyIsNotInFile : public exception {
    const char *what() const throw() { return "ERROR: Family is not in the file"; }
} FamilyIsNotInFile;

enum ACTIVITY {
    NONE, //  טרם בחר חוג
    SWIMMING,          // שחיה
    GYMNATSTICS,         // התעמלות קרקע
    DANCE = 4,     // מחול
    ART = 8,    // אומנות
    SELF_DEFENSE = 16, // הגנה עצמית
    MUSIC = 32, // מוסיקה
    DRAMA = 64, // דרמה
    BASKETBALL = 128  // כדור סל
};

void setFile(fstream &file) {
    Family temp;
    for (int i = 1; i < 101; ++i) {
        file.write((char *) &temp, sizeof(Family));
    }
}

void add(fstream &file) { //adding family to the file, if the family is already in the file, throw exception
    int _familyId, _numOfFamilyMembers, _phoneNumber, writeOffset;
    char _familyName[21]{};
    cout << "enter the family's:  id, name, amount of people and a phone number: " << endl;
    Family tmp;
    cin >> _familyId >> _familyName >> _numOfFamilyMembers >> _phoneNumber;//input info
    int offset = _familyId * sizeof(Family);
    if (_familyId < 1 || 100 < _familyId){
        throw InvalidFamilyNum;   //throw "ERROR: Invalid family number"
    }
    //check if the family is already in the file, throw exception
    file.seekg(offset,ios::beg);
    file.read((char *) &tmp, sizeof(Family));
    if (tmp.getFamilyId() == _familyId)
        throw familyInTheFile;

    tmp.setFamilyId(_familyId);
    tmp.setFamilyName(_familyName);
    tmp.setNumOfFamilyMembers(_numOfFamilyMembers);
    tmp.setPhoneNumber(_phoneNumber);
    tmp.setActivityList(NONE);


    file.seekp(offset,ios::beg);
    file.write((char *) &tmp, sizeof(Family));

}


void del(fstream &file, int id) { //deleting family from the file
    Family temp; //temp family
    if (id < 1 || id > 100) { //check if id is valid
        throw InvalidFamilyNum;
    }
    int offset=id * sizeof(Family);
    file.seekg(offset,ios::beg);
    file.read((char *) &temp, sizeof(Family));
    if (temp.getFamilyId() == id) {
        file.seekp(offset,ios::beg);
        temp.setFamilyId(0);
        file.write((char *) &temp, sizeof(Family));
        return;
    }
    throw FamilyIsNotInFile;
}

int count(fstream &file, int activityType) { //counting families that have activityType
    Family temp;
    int sum = 0 ;
    for (int i = 1; i < 101; ++i) {
        int offset =i * sizeof(Family);
        file.seekg(offset, ios::beg);
        file.read((char *) &temp, sizeof(Family));
        if (temp.getActivityList() & activityType)
            ++sum;
    }
    return sum;
}

bool checkValid(char ans) { return ans == 'n' || ans == 'N' || ans == 'y' || ans == 'Y'; }//check if answer is valid

bool canRegister(fstream &file, int activity) { return (count(file, activity) < 10); }//check if family can register to activity

void update(fstream &file, int id, queue<Family> &whaitingList) { //updating family activity list
    if (id < 1 || id > 100) { //check if id is valid
        throw InvalidFamilyNum;
    }
    int offset =id * sizeof(Family);
    Family temp;
    file.seekg(offset);
    file.read((char *) &temp, sizeof(Family));
    if (temp.getFamilyId() == 0) {
        throw FamilyIsNotInFile;
    }

    char msg[8][43] = { //messages for user
            {"Do you want to register for swimming?\n"},
            {"Do you want to register for gymnastics?\n"},
            {"Do you want to register for dance?\n"},
            {"Do you want to register for art?\n"},
            {"Do you want to register for self defense?\n"},
            {"Do you want to register for music?\n"},
            {"Do you want to register for drama?\n"},
            {"Do you want to register basketball?\n"}
    };
    char choice[8]; //user choice
    short _activity = 1;
    for (int i = 0; i < 8; ++i, _activity *= 2) { //loop for all activities
        cout << msg[i]; //print message
        cin >> choice[i]; //input choice
        if (!checkValid(choice[i]))  //check if answer is valid
            throw invalidResponse;
        if ((choice[i] == 'y' || choice[i] == 'Y') && canRegister(file, _activity)) { //check if answer is valid and if family can register
            temp.setActivityList(temp.getActivityList() + _activity);
        }
    }

    file.seekp(offset);
    file.write((char *) &temp, sizeof(Family));

    // add all the activities that can not be registered to the waiting list
    Family k;
    file.seekg(offset);
    file.read((char *) &k, sizeof(Family));
    k.setActivityList(0);
    for (int i = 0, _activity = 1; i < 8; ++i, _activity *= 2) {
        if ((choice[i] == 'y' || choice[i] == 'Y') && !canRegister(file, _activity)){
            k.setActivityList(k.getActivityList()+_activity);
       }
    }
    whaitingList.push(k);
}

void waiting(queue<Family> &q) {
    // print all the ditails of every family in the waiting list
    while (!q.empty()) {
        Family temp = q.front();
        q.pop();
        //cout << "Family ID: " << temp.getFamilyId() << endl;
        cout << "family name: " << temp.getFamilyName() << endl;
        cout << "number of persons: " << temp.getNumOfFamilyMembers() << endl;
        cout << "Phone Number: " << temp.getPhoneNumber() << endl;
        //cout << "Activity List: ";
        if (temp.getActivityList() & SWIMMING) {
            cout << "SWIMMING ";
        }
        if (temp.getActivityList() & GYMNATSTICS) {
            cout << "GYMNASTICS ";
        }
        if (temp.getActivityList() & DANCE) {
            cout << "DANCE ";
        }
        if (temp.getActivityList() & ART) {
            cout << "ART ";
        }
        if (temp.getActivityList() & SELF_DEFENSE) {
            cout << "SELF DEFENSE ";
        }
        if (temp.getActivityList() & MUSIC) {
            cout << "MUSIC ";
        }
        if (temp.getActivityList() & DRAMA) {
            cout << "DRAMA ";
        }
        if (temp.getActivityList() & BASKETBALL) {
            cout << "BASKETBALL ";
        }
        cout << endl;
    }
}

void print(fstream &file, int id) {
    if (id < 1 || id > 100)
        throw InvalidFamilyNum;
    Family temp;


    int offset=id * sizeof(Family);
    file.seekg(offset, ios::beg);//   id n is in place n-1 in file.
    file.read((char *) &temp, sizeof(Family));
    if (temp.getFamilyId() == 0) // check if id is in file
        throw FamilyIsNotInFile;
    cout << "family name: " << temp.getFamilyName() << endl;
    cout << "number of persons: " << temp.getNumOfFamilyMembers() << endl;
    cout << "phone number: " << temp.getPhoneNumber() << endl;
    // if activity list is not empty

    if ((temp.getActivityList() & SWIMMING) != 0) {
        cout << "SWIMMING" << endl;
    }
    if ((temp.getActivityList() & GYMNATSTICS) != 0) {
        cout << "GYMNATSTICS" << endl;
    }
    if ((temp.getActivityList() & DANCE) != 0) {
        cout << "DANCE" << endl;
    }
    if ((temp.getActivityList() & ART) != 0) {
        cout << "ART" << endl;
    }
    if ((temp.getActivityList() & SELF_DEFENSE) != 0) {
        cout << "SELF DEFENSE" << endl;
    }
    if ((temp.getActivityList() & MUSIC) != 0) {
        cout << "MUSIC" << endl;
    }
    if ((temp.getActivityList() & DRAMA) != 0) {
        cout << "DRAMA" << endl;
    }
    if ((temp.getActivityList() & BASKETBALL) != 0) {
        cout << "BASKETBALL" << endl;
    }

}


void handleCount(fstream &file) {
    int snum;
    cout << "enter activity number to count:\n";
    cout
            << "Choices are:\n1 SWIMMING\n2 GYMNASTICS\n3 DANCE\n4 ART\n5 SELF DEFENSE \n6 MUSIC \n7 DRAMA\n8 BASKETBALL\n"
            << endl;
    cin >> snum;
    cout << "there are ";
    switch (snum) {
        case 1:
            cout << count(file, SWIMMING);
            break;
        case 2:
            cout << count(file, GYMNATSTICS);
            break;
        case 3:
            cout << count(file, DANCE);
            break;
        case 4:
            cout << count(file, ART);
            break;
        case 5:
            cout << count(file, SELF_DEFENSE);
            break;
        case 6:
            cout << count(file, MUSIC);
            break;
        case 7:
            cout << count(file, DRAMA);
            break;
        case 8:
            cout << count(file, BASKETBALL);
            break;
    }
    cout << " families registered\n" << endl;
}


int main() {
    queue<Family> q;

    queue<Family> jv;
    fstream file;
    file.open("families.txt", ios::binary | ios::in | ios::out);
    if (!file) {
        cout << "ERROR: couldn't open file\n";
        return 0;
    }
    setFile(file);
    file.clear();

    int choice;
    int snum;
    int cnum;
    cout
            << "Choices are:\n0 to exit\n1 to add a family\n2 to delete a family\n3 to  count number of families signed up\n4 to update the activities of a family \n5 print the waiting list \n6 to print a family\n";
    cout << "enter 0-6:\n";
    cin >> choice;
    while (choice) {
        try {
            switch (choice) {
                case ADD://add to the file
                    add(file);
                    break;
                case DEL://delete from file
                    cout << "enter number of family to delete:\n";
                    cin >> snum;
                    del(file, snum);
                    break;
                case COUNT:
                    handleCount(file);
                    break;
                case UPDATE://update the list of classes of a family
                    cout << "enter number of family to update:\n" << endl;
                    cin >> snum;
                    update(file, snum, jv);
                    break;
                case WAITING://update the list of classes of a waiting family
                    waiting(jv);
                    break;

                case PRINT://print the details of a specific family
                    cout << "enter number of family to print:\n";
                    cin >> snum;
                    print(file, snum);
                    break;
                default:
                    cout << "ERROR: invalid choice\n";

            }
        }// try
        catch (exception &e) {
            cout << e.what();
        }
        cout << "\nenter 0-6:\n";
        cin >> choice;

    }
    file.close();
    return 0;
}
