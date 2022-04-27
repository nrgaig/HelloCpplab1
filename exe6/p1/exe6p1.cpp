#include "FullTime.cpp"
#include "PartTime.cpp"
#include <iostream>

using namespace std;

const int FULL_SIZE = 3, PART_SIZE = 3;

int main() {
    FullTime arrF[FULL_SIZE];
    for (int i = 0; i < FULL_SIZE; i++) {
        try {
            cin >> arrF[i];
        }
        catch (const char *str) {
            cout << str << endl;
            i--;
        }
    }


    PartTime arrP[PART_SIZE];
    for (int i = 0; i < PART_SIZE; i++) {
        try {
            cin >> arrP[i];
        }
        catch (const char *str) {
            cout << str << endl;
            i--;
        }
    }


    for (int i = 0; i < FULL_SIZE; i++) {
        cout << arrF[i];
        cout << "After Bonus: " << arrF[i].salaryAfterBonus() << endl;
    }


    for (int i = 0; i < PART_SIZE; i++) {
        cout << arrP[i];
        cout << "After Bonus: " << arrP[i].salaryAfterBonus() << endl;
    }
    return 0;
}
