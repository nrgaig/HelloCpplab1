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

class InvalidResponse:public exception { const char *what() const throw() { return "ERROR: Invalid response";}} invalidResponse;
class InvalidFamilyNumber:public exception { const char *what() const throw() { return "ERROR: Invalid family number";}} InvalidFamilyNum;
class fFamilyInTheFile:public exception { const char *what() const throw() { return "ERROR: Family is already in the file";}} familyInTheFile;

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
    writeOffset= sizeof(Family)*(_familyId-1);// prepare offset from beginning
    Family input{_familyId, _familyName, _numOfFamilyMembers, _phoneNumber,NONE};
    file.seekp(writeOffset);
    file.write((char*)&input,sizeof (Family));//writing into file in place




}

void del(fstream &file, int id) {
    Family temp;
    if (id < 1 || id > 100) {
        //“ERROR: Invalid family number”.
    }
    while (!file.eof()) {
        file.read((char *) &temp, sizeof(Family));
        if (temp.getFamilyId() == id) {
            temp.setFamilyId(0);
            return;
        }
    }
//    “ERROR: Family is not in the file”
}

int count(fstream &file, int activityType) {
    Family temp;
    int sum = 0;
    while (!file.eof()) {
        file.read((char *) &temp, sizeof(Family));
        if ((temp.getActivityList() & activityType) == 0) {
            sum++;
        }
    }
    return sum;
}

bool check_valid(char ans) {
    if (ans != 'n' && ans != 'N' && ans != 'y' && ans != 'Y') {
        //“ERROR: Invalid response”
        return false;
    }
    return true;
}

bool canReg(fstream &file, int activity) {
    return (count(file, activity) < 10);
}

void update(fstream &file, int id, queue<Family> whaitingList) {
    if (id < 1 || id > 100) {
        //“ERROR: Invalid family number”.
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
        //“ERROR: Family is not in the file”
    }
    file.clear();
    char msg[8][43] = {
            {"Do you want to register for swimming?\n"},
            {"Do you want to register for gymnastics?\n"},
            {"Do you want to register for dance?\n"},
            {"Do you want to register for art?\n"},
            {"Do you want to register for self defense?\n"},
            {"Do you want to register for music?\n"},
            {"Do you want to register for drama?\n"},
            {"Do you want to register basketball?\n"}};
    char choice[9];
    for (int i = 0, _activity = 1; i < 8; ++i, _activity *= 2) {
        cout << msg[i];
        cin >> choice[i];
        if(check_valid(choice[i]) &&  && canReg(file, _activity)){
            temp.setActivityList(temp.getActivityList()+_activity);
        }
    }



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
