#include "Family.h"
#include <queue>
#include <iostream>
#include <fstream>
#include <exception>
#include <cstring>

using namespace std;


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
    for (int i = 0; i < 100; ++i) {
        file.write((char *) &temp, sizeof(Family));
    }
}

void add(fstream &file) { //adding family to the file
    int _familyId, _numOfFamilyMembers, _phoneNumber, writeOffset;
    char _familyName[21]{};
    short _activityList;

    Family tmp;
    cin >> _familyId >> _familyName >> _numOfFamilyMembers >> _phoneNumber;//input info
    if (_familyId < 1 || 100 < _familyId)
        throw InvalidFamilyNum;   //throw "ERROR: Invalid family number"
    file.seekg(0);// pointing read to start of file
    while (!file.eof()) {//check if famId is not already in file
        file.read((char *) &tmp, sizeof(Family));//reading family from file
        if (tmp.getFamilyId() == _familyId) {
            throw familyInTheFile;   //throw "ERROR: Family is already in the file";
        }
    }
    // insert new family into file
    writeOffset = sizeof(Family) * (_familyId - 1);// prepare offset from beginning
    Family input{_familyId, _familyName, _numOfFamilyMembers, _phoneNumber, NONE};
    file.seekp(writeOffset);
    file.write((char *) &input, sizeof(Family));//writing into file in place




}

void del(fstream &file, int id) { //deleting family from the file
    Family temp; //temp family
    if (id < 1 || id > 100) { //check if id is valid
        throw InvalidFamilyNum;
    }
    while (!file.eof()) { //check if id is in file
        file.read((char *) &temp, sizeof(Family)); //reading family from file
        if (temp.getFamilyId() == id) {
            temp.setFamilyId(0); //set family id to 0
            return;
        }
    }
    throw FamilyIsNotInFile;
}

int count(fstream &file, int activityType) { //counting families that have activityType
    Family temp;
    int sum = 0;
    while (!file.eof()) {
        file.read((char *) &temp, sizeof(Family));
        if ((temp.getActivityList() & activityType) == 0) { //check if family has activityType
            sum++;  //increment sum
        }
    }
    return sum;
}

bool check_valid(char ans) { //check if answer is valid
    if (ans != 'n' && ans != 'N' && ans != 'y' && ans != 'Y') {
        throw invalidResponse;
    }
    return true;
}

bool canReg(fstream &file, int activity) { //check if family can register to activity
    return (count(file, activity) < 10);
}

void update(fstream &file, int id, queue<Family> whaitingList) { //updating family activity list
    if (id < 1 || id > 100) { //check if id is valid
        throw InvalidFamilyNum;
    }
    Family temp;
    bool isInFile = false;
    while (!file.eof()) {
        file.read((char *) &temp, sizeof(Family));
        if (temp.getFamilyId() == id) {
            isInFile = true;
            break;
        }
    }
    if (!isInFile) {
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
            {"Do you want to register basketball?\n"}};
    char choice[9]; //user choice
    for (int i = 0, _activity = 1; i < 8; ++i, _activity *= 2) { //loop for all activities
        cout << msg[i]; //print message
        cin >> choice[i]; //input choice
        if (check_valid(choice[i]) && (choice[i] == 'y' || choice[i] == 'Y') && canReg(file, _activity)) { //check if answer is valid and if family can register
            temp.setActivityList(temp.getActivityList() + _activity);
        }
    }
    file.write((char *) &temp, sizeof(Family));//writing into file in place

    for (int i = 0, _activity = 1; i < 8; ++i, _activity *= 2) { //loop for all activities
        if ((choice[i] == 'y' || choice[i] == 'Y') && !canReg(file, _activity)) {
            whaitingList.push(temp);
        }
    }
}

void waiting(queue<Family> &q) {
    // print all the ditails of every family in the waiting list
    while (!q.empty()) {
        Family temp = q.front();
        q.pop();
        cout << "Family ID: " << temp.getFamilyId() << endl;
        cout << "Family Name: " << temp.getFamilyName() << endl;
        cout << "Family Members: " << temp.getNumOfFamilyMembers() << endl;
        cout << "Phone Number: " << temp.getPhoneNumber() << endl;
        cout << "Activity List: ";
        if (temp.getActivityList() & SWIMMING) {
            cout << "swimming ";
        }
        if (temp.getActivityList() & GYMNATSTICS) {
            cout << "gymnastics ";
        }
        if (temp.getActivityList() & DANCE) {
            cout << "dance ";
        }
        if (temp.getActivityList() & ART) {
            cout << "art ";
        }
        if (temp.getActivityList() & SELF_DEFENSE) {
            cout << "self defense ";
        }
        if (temp.getActivityList() & MUSIC) {
            cout << "music ";
        }
        if (temp.getActivityList() & DRAMA) {
            cout << "drama ";
        }
        if (temp.getActivityList() & BASKETBALL) {
            cout << "basketball ";
        }
        cout << endl;
    }
}

void print(fstream &file, int id) {
    if (id < 1 || id > 100) {
        throw InvalidFamilyNum;
    }
    Family temp;
    bool isInFile = false;
    while (!file.eof()) {
        file.read((char *) &temp, sizeof(Family));
        if (temp.getFamilyId() == id) {
            isInFile = true;
            break;
        }
    }
    if (!isInFile) {
        throw FamilyIsNotInFile;
    }
    cout << "Family ID: " << temp.getFamilyId() << endl;
    cout << "Family Name: " << temp.getFamilyName() << endl;
    cout << "Family Members: " << temp.getNumOfFamilyMembers() << endl;
    cout << "Phone Number: " << temp.getPhoneNumber() << endl;
    cout << "Activity List: " << temp.getActivityList() << endl;
}


void handleCount(fstream &file) {
    int snum;
    cout << "enter activity number to count:\n";
    cout
            << "Choices are:\n1 SWIMMING\n2 GYMNASTICS\n3 DANCE\n4 ART\n5 SELF DEFENSE \n6 MUSIC \n7 DRAMA\n8 BASKETBALL\n";
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
    cout << " families registered\n";
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
                    cout << "enter number of family to update:\n";
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
