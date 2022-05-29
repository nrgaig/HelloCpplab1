/*********************************************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482                       *
 * cpp lab - Meir Litman                                                         *
 * exercise 10 task 1                                                            *
 * main program manage commending array in IDF after "Shomer Hachomot" operation *
**********************************************************************************/

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include "Soldier.h"
#include "Commander.cpp"
#include "Officer.cpp"
#include "PrivateSoldier.cpp"

using namespace std;

enum option {
    EXIT,    //	סיום התוכנית
    ADD_NEW_SOLDIER,    //	הוספת חייל חדש
    DESERVES_MEDAL,    //	הדפסת פרטי כל החיילים הזכאים לצל"ש
    HIGHEST_SOCIOMETRIC,    //הדפסת שם (משפחה ופרטי) של  החייל בעל ציון סוציומטרי מקסימלי
    PRIVATE_MEDAL_COUNT,    //	הדפסת מספר החיילים הטירוניים הזכאים לצל"ש
    NONCOMBAT_COMMANDER,    //	הדפסת שמות (משפחה ופרטי) של המפקדים שאינם בקרבי
    SUPER_SOLDIER,   //הדפסת הודעה מתאימה, האם קיים חייל שהשתתף ביותר מ- 15  מבצעים צבאיים
    REMOVE_OFFICER,    //	מחיקת כל החיילים הקצינים שלא השתתפו כלל במבצע צבאי
};

void add(vector<Soldier *> &SoldierList) {
    // add new soldier to the list
    cout << "choose a soldier\n";
    cout << "enter 1 to add a private\n";
    cout << "enter 2 to add a commander\n";
    cout << "enter 3 to add an officer\n";
    int type;
    cin >> type;
    enum SoldierType {
        PRIVATE = 1,
        COMMANDER,
        OFFICER
    };
    switch (type) {
        case PRIVATE: {
            int id, numOfOperations, *grades;
            string firstName, lastName;
            cout << "enter id, first name, last name and number of operations" << endl;
            cin >> id >> firstName >> lastName >> numOfOperations;
            cout << "enter " << numOfOperations << " grades\n";
            grades = new int[numOfOperations];
            for (int i = 0; i < numOfOperations; i++) {
                cin >> grades[i];
            }
            SoldierList.push_back(new PrivateSoldier(id, firstName, lastName, numOfOperations, grades));
            break;
        }
        case COMMANDER: {
            int id, numOfOps, *grades;
            string firstName, lastName;
            bool isBelligerent;
            cout << "enter id, first name, last name and number of operations" << endl;
            cin >> id >> firstName >> lastName >> numOfOps;
            cout << "enter " << numOfOps << " grades\n";
            grades = new int[numOfOps];
            for (int i = 0; i < numOfOps; i++) {
                cin >> grades[i];
            }
            cout << "enter 1 if the soldier is combat and 0 if not" << endl;
            cin >> isBelligerent;
            SoldierList.push_back(new Commander(id, firstName, lastName, numOfOps, grades, isBelligerent));
            break;
        }
        case OFFICER: {
            int id, numOfOps, sociometry;
            string firstName, lastName;
            cout << "enter id, first name, last name and number of operations" << endl;
            cin >> id >> firstName >> lastName >> numOfOps;
            cout << "enter the sociometric score" << endl;
            cin >> sociometry;
            SoldierList.push_back(new Officer(id, firstName, lastName, numOfOps, sociometry));
            break;
        }
        default:
            cout << "invalid input\n";
            break;
    }


}

void printMedalList(vector<Soldier *> SoldierList) {
    // print all soldiers that deserve a medal

    for (auto &i: SoldierList) {
        if (i->medal()) {
            i->print();
        }
    }
}   //השלם\י פרמטר- ווקטור או רשימה
Soldier *highestSociometricScore(vector<Soldier *> SoldierList) {
    // return the soldier with the highest sociometric score
    int max = 0;
    Soldier *maxSoldier = nullptr;
    for (auto &i: SoldierList) { // running on SoldierList
        if (i->soldierType() ==
        "officer") // if our soldier is Officer check if he has the highest stoichiometry
            if (((Officer *) i)->getSociometric() > max) { // if he has made him  maxSoldier
                max = ((Officer *) i)->getSociometric();
                maxSoldier = i;
            }
    }
    return maxSoldier;
}

int main() {

    Soldier *s;
    vector<Soldier *> soldierList;
    int op;
    cout << "enter 0-7\n";
    cin >> op;
    while (op != EXIT) {
        switch (op) {
            case ADD_NEW_SOLDIER:
                add(soldierList);  //add new soldier to the list
                break;
            case DESERVES_MEDAL:
                printMedalList(soldierList);  //print all eligble soldiers
                break;
            case HIGHEST_SOCIOMETRIC:   // print the officer with the highest sociometric score
                s = highestSociometricScore(soldierList);
                cout << "Officer with the highest sociometric score: ";
                cout << s->getFirstName() << ' ' << s->getLastName() << endl;

                break;
            case PRIVATE_MEDAL_COUNT:
                cout << "number of privates that received medals: ";
                // print the number of privates that received medals
                cout << count_if(soldierList.begin(), soldierList.end(), [](Soldier *i) {
                    return i->medal();
                });
                cout << endl;
                break;
            case NONCOMBAT_COMMANDER:
                cout << "list of noncombat commanders: ";    //print a list of noncombat commanders
                for_each(soldierList.begin(), soldierList.end(), [](Soldier *i) {
                    if (i->soldierType() == "commander" &&
                        !((Commander *) i)->getIsBelligerent()) { i->print(); }
                });
                cout << endl;
                break;
            case SUPER_SOLDIER:
                if (any_of(soldierList.begin(), soldierList.end(), [](Soldier *i) {
                    return i->getNumOfOps() > 15;
                }))// soldier that operated in more than 15 operations
                    cout << "there is at least one soldier that did more than 15 operations\n";
                else
                    cout << "no soldier did more than 15 operations\n";
                break;
            case REMOVE_OFFICER://remove all the solders that did not fight in combat
                vector<Soldier *>::iterator pend;
                pend = remove_if(soldierList.begin(), soldierList.end(),
                                 [](Soldier *i) { return i->getNumOfOps() < 1; });
                for_each(soldierList.begin(), pend, [](Soldier *i) {
                    i->print();
                });      // printing vector after removing
                break;
        };
        cout << "enter 0-7\n";
        cin >> op;
    }


    return 0;

}
