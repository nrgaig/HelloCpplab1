/*********************************************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482                       *
 * cpp lab - Meir Litman                                                         *
 * exercise 10 task 1                                                            *
 * main program manage commending array in idf after "Shomer Hachomot" operation *
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

void add(vector<Soldier *> SoldierList) {
    // add new soldier to the list
    cout << "choose a soldier\n";
    cout << "enter 1 to add a private\n";
    cout << "enter 2 to add a commander\n";
    cout << "enter 3 to add an officer\n";
    int type;
    cin >> type;
    enum SoldierType {
        PRIVATE=1,
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
            int id, numOfOps;
            string firstName, lastName;
            bool isBelligerent;
            cout << "enter id, first name, last name and number of operations" << endl;
            cin >> id >> firstName >> lastName >> numOfOps;
            cout << "enter 1 if the soldier is combat and 0 if not" << endl;
            cin >> isBelligerent;
            SoldierList.push_back(new Commander(id, firstName, lastName, numOfOps,0, isBelligerent));
            break;
        }
        case OFFICER: {
            int id, numOfOps, sociometry;
            string firstName, lastName;
            cout << "enter id, first name, last name and number of operations" << endl;
            cin >> id >> firstName >> lastName >> numOfOps;
            cout << "Enter the sociometric score" << endl;
            cin >> sociometry;
            SoldierList.push_back(new Officer(id, firstName, lastName, numOfOps, sociometry));
            break;
        }
    }



}

void printMedalList(vector<Soldier*>SoldierList){
    // print all soldiers that deserve a medal

    for (auto & i : SoldierList) {
        if (i->medal()) {
            i->print();
        }
    }
}   //השלם\י פרמטר- ווקטור או רשימה
Soldier *highestSociometricScore(vector<Soldier*>SoldierList){
    // return the soldier with the highest sociometric score
    int max = 0;
    Soldier *maxSoldier = nullptr;
    for (int i = 0; i < SoldierList.size(); i++) { // running on SoldierList
        if (SoldierList[i]->soldierType().compare("officer")==0) // if our soldier is Officer check if he has the highest stoichiometry
            if (((Officer *)SoldierList[i])->getSociometric() > max){ // if he has made him  maxSoldier
            max = ((Officer *)SoldierList[i])->getSociometric();
            maxSoldier = SoldierList[i];
            }
    }
//    for (auto &i : SoldierList) {
//        if (i->soldierType()== "officer") {
//            //((Officer *) soldier)->getSociometric();
//            if ((Officer *) i->getSociometry() > max) {
//                max = i->getSociometry();
//                maxSoldier = i;
//            }
//        }
//    }
    return maxSoldier;
}   //השלם\י פרמטר- ווקטור או רשימה

int main() {

    Soldier *s;
    vector<Soldier *> soldierList;   // הצהרה על ווקטור או רשימה של חיילים
    int op;
    cout << "enter 0-7\n";
    cin >> op;
    while (op != EXIT) {
        switch (op) {
            case ADD_NEW_SOLDIER:
                add(____________);  //הוספת חייל חדש
                break;
            case DESERVES_MEDAL:
                printMedalList(____________);  //הדפסת פרטי הזכאים לצל"ש
                break;
            case HIGHEST_SOCIOMETRIC:   //הדפסת שם הקצין בעל ציון סוציומטרי גבוה ביותר
                s = highestSociometricScore(soldierList); // השלם\י פרמטר-וקטור או רשימה
                cout << "Officer with the highest sociometric score: ";
                cout << s->getFirstName() << ' ' << s->getLastName() << endl;

                break;
            case PRIVATE_MEDAL_COUNT:
                cout << "number of privates that received medals: ";
                ________________ //הדפסת מספר הזכאים לצל"ש בטירונים
                cout << endl;
                break;
            case NONCOMBAT_COMMANDER:
                cout << "list of noncombat commanders: ";    //הדפסת רשימת(שם משפחה ופרטי) החיילים המפקדים שאינם בקרבי
                ________________
                cout << endl;
                break;
            case SUPER_SOLDIER:
                if (______________) // קיים חייל שהשתתף יובתר מ- 15 מבצעים צבאיים

                    cout << "there is at least one soldier that did more than 15 operations\n";
                else
                    cout << "no soldier did more than 15 operations\n";
                break;
            case REMOVE_OFFICER://מחיקה מהווקטור/רשימה של כל החיילם קצינים שאינם השתתפו כלל במבצעים צבאיים
                ________________
                        ________________ //הדפסת כל הרשימה לאחר מחיקת האיברים
                break;
        };
        cout << "enter 0-7\n";
        cin >> op;
    }


    return 0;
}
