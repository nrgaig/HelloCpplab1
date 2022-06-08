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
    int _familyId, _numOfFamilyMembers, _phoneNumber;
    char _familyName[21]{};
    short _activityList;
    Family tmp;

    cin >> _familyId >> _familyName >> _numOfFamilyMembers >> _phoneNumber;//input info
    while (!file.eof()) {
        file.read((char *) &tmp, sizeof(Family));
        if (tmp.getFamilyId() == _familyId) {
            globError.setMessage("ERROR: Invalid family number");
            throw globError;
        }
        //throw "ERROR: Invalid family number";   //throw "ERROR: Invalid family number"


    }
    //check if famId is not already in file
    //    throw "ERROR: Family is already in the file";

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

void check_valid(char ans) {
    if (ans != 'n' && ans != 'N' && ans != 'y' && ans != 'Y') {
        //“ERROR: Invalid response”
    }
}

void reg(fstream &file, Family& family, queue<Family>& q , int activity){
    if (count(file, activity) < 10) {
        family.setActivityList(family.getActivityList() + activity);
    } else {

    }
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
    char swimming, gymnastics, dance, art, self_defense, music, drama, basketball;
    cout << "Do you want to register for swimming?" << endl;
    cin >> swimming;
    check_valid(swimming);

    cout << "Do you want to register for gymnastics?" << endl;
    cin >> gymnastics;
    check_valid(gymnastics);

    cout << "Do you want to register for dance?" << endl;
    cin >> dance;
    check_valid(dance);

    cout << "Do you want to register for art?" << endl;
    cin >> art;
    check_valid(art);

    cout << "Do you want to register for self defense?" << endl;
    cin >> self_defense;
    check_valid(self_defense);

    cout << "Do you want to register for music?" << endl;
    cin >> music;
    check_valid(music);

    cout << "Do you want to register for drama?" << endl;
    cin >> drama;
    check_valid(drama);

    cout << "Do you want to register basketball?" << endl;
    cin >> basketball;
    check_valid(basketball);
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
