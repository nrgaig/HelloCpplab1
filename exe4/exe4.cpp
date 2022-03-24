

//main program we requested to modify - given by exercise author

#include <iostream>
#include "Clock.h"
#include "Account.h"

using namespace std;

enum ACTION {
    STOP,
    BALANCE,
    DEPOSIT,
    WITHDRAW,
    SUM_DEPOSIT,
    SUM_WITHDRAW
};
ACTION menu() {
    cout << "enter 1 to get account balance" << endl;
    cout << "enter 2 to deposit money" << endl;
    cout << "enter 3 to withdraw money" << endl;
    cout << "enter 4 to see the sum of all deposits" << endl;
    cout << "enter 5 to see the sum of all withdrawals" << endl;
    cout << "enter 0 to stop" << endl;
    int x;
    cin >> x;
    return (ACTION)x;
}
int findAccount(Account* bank, int size) {
    int number, code;
    cout << "please enter account number:\n";
    cin >> number;
    int i = 0;
    while (i < size && bank[i].getAccountNumber() != number)
        i++;
    if (i >= size)
        throw "ERROR: no such account number\n";
    cout << "please enter the code:\n";
    cin >> code;
    if (bank[i].getCode() == code)
        return i;
    throw "ERROR: wrong code!\n";
}
void printTransaction(Account a, ACTION ac, Clock& c) {
    cout << c << "\n";
    switch (ac) {
        case BALANCE: cout << "account #: " << a.getAccountNumber() << "\n";
            cout << "balance: " << a.getBalance() << endl;
            break;
        case DEPOSIT:
        case WITHDRAW: cout << "account #: " << a.getAccountNumber() << "\n";
            cout << "new balance: " << a.getBalance() << endl;
            break;
        case SUM_DEPOSIT:
            cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
            break;
        case SUM_WITHDRAW:
            cout << "sum of all withdrawals: " << Account::getSumWithdraw() << endl;
            break;
    }
}
void getBalance(Account* bank, int size, Clock& c) {
    int i;
    try {// try to find account - if there is error catch error message and
        i= findAccount(bank, size);
    }
    catch (const char *msg) {
        c += 20;
        cout << c << "\t" << msg << "\n";
        return;
    }
    c += 20;
    printTransaction(bank[i], BALANCE, c);

}
void cashDeposit(Account* bank, int size, Clock& c) {
    int i;
    try {// try to find account - if there is error catch error message
        i= findAccount(bank, size);
    }
    catch (const char *error) {
        cout << c << "\t" << error << "\n";
        return;
    }
    float amount;
    cout << "enter the amount of the deposit:\n ";
    cin >> amount;
    try {// try to deposit amount into account - if there is error catch error message
        bank[i].deposit(amount);
    }
    catch (const char *error) {
        c += 30;
        cout << c << "\t" << error << "\n";
        return;
    }
    c += 30;
    printTransaction(bank[i], DEPOSIT, c);
}
void cashWithdraw(Account* bank, int size, Clock& c) {
    int i;
    try {// try to find account - if there is error catch error message
        i= findAccount(bank, size);
    }
    catch (const char *error) {
        cout << c << "\t" << error << "\n";
        return;
    }
    float amount;
    cout << "enter the amount of money to withdraw:\n ";
    cin >> amount;
    try {// try to draw amount from account - if there is error catch error message
        bank[i].withdraw(amount);
    }
    catch (const char *error) {
        cout << c << "\t" << error << "\n";
        c += 50;
        return;
    }
    c += 50;
    printTransaction(bank[i], WITHDRAW, c);
}
void checkAccount(Account bank[], int i) {
    for (int j = 0; j < i; j++)
        if (bank[i].getAccountNumber() == bank[j].getAccountNumber())
            throw "ERROR: account number must be unique!\n";
}
int main() {
    const int SIZE = 2; //todo it might do some problems
    Clock c(8, 0, 0);

    Account bank[SIZE];// creating bank - (array of accounts) and getting accs values
    cout << "enter account number, code and email for " << SIZE << " accounts:\n";
    for (int i = 0; i < SIZE; i++) {
        try {
            cin >> bank[i];
            checkAccount(bank, i);
        }
        catch (const char* msg) {
            cout << c << '\t' << msg;
            i--;
        }
    }//end of creating bank

    ACTION ac = menu();
    while (ac) {
        switch (ac) {
            case BALANCE: getBalance(bank, SIZE, c);
                break;
            case WITHDRAW:cashWithdraw(bank, SIZE, c);
                break;
            case DEPOSIT:cashDeposit(bank, SIZE, c);
                break;
            case SUM_DEPOSIT:c += 60;
                printTransaction(bank[0], SUM_DEPOSIT, c);
                break;
            case SUM_WITHDRAW:c += 60;
                printTransaction(bank[0], SUM_WITHDRAW, c);
        }

        ac = menu();
    }

    return 0;
}
/*
enter account number, code and email for 2 accounts:
123  4444 me@gmail.com
234 5555  you@walla.co.il
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
1
please enter account number:
123
please enter the code:
4445
08:00:20	ERROR: wrong code!

enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
1
please enter account number:
123
please enter the code:
4444
08:00:40
account #: 123
balance: 0
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
2
please enter account number:
123
please enter the code:
4444
enter the amount of the deposit:
 20000
08:01:10	ERROR: cannot deposit more than 10000 NIS!

enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
2
please enter account number:
12
08:01:10	ERROR: no such account number

enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
3
please enter account number:
123
please enter the code:
4444
enter the amount of money to withdraw:
 500
08:01:60
account #: 123
new balance: -500
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
4
08:02:60
sum of all deposits: 0
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
5
08:03:60
sum of all withdrawals: 1
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
0

*/
