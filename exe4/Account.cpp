//
// Created by itayo on 21/03/2022.
// edited by maor
//

#include "Account.h"
#include <iostream>

using namespace std;

int Account::sumWithdraw = 0;//init counter of all draws of all account
int Account::sumDeposit = 0;//init counter of all deposits of all account


Account::Account() : accountNumber(0), code(0), balance(0), email("") {} // empty constructor - init all properties to default values

Account::Account(int _accountNumber, int _code, int _balance, const string& _email) {//constructor
    if (_code < 1000||_code>9999)//if _code is not 4 digit integer it's not valid
        throw "ERROR: code must be of 4 digits!\n";// throw error message

    size_t locationOfShtrudel = _email.find('@');// search for '@' sign in email string
    if (locationOfShtrudel == string::npos)// if email doesnt contains '@'
        throw "ERROR: email must contain @!\n";// throw error message

    if (_email.find(".co.il", locationOfShtrudel + 1) == string::npos &&
        _email.find(".com", locationOfShtrudel + 1) == string::npos)// search for .locale in email string
        throw "ERROR: email must end at .com or .co.il!\n";// throw error message

    //if all come through with no errors init properties with given values
    accountNumber = _accountNumber;
    code = _code;
    balance = _balance;
    email = _email;

}

int Account::getAccountNumber() const {
    return accountNumber;
}

int Account::getCode() const {
    return code;
}

int Account::getBalance() const {
    return balance;
}

const string &Account::getEmail() const {
    return email;
}

istream &operator>>(istream &inStream, Account &account) {// istream operator
    int _accountNumber, _code;
    string _email;
    inStream >> _accountNumber >> _code >> _email;// getting values from stream

    if (_code < 1000 || _code > 9999)// checking code validation
        throw "ERROR: code must be of 4 digits!\n";

    size_t atIndex = _email.find('@');// checking email validation
    if (atIndex == string::npos)
        throw "ERROR: email must contain @!\n";
    if (_email.find(".com", atIndex + 1) == string::npos && _email.find(".co.il", atIndex + 1) == string::npos)
        throw "ERROR: email must end at .com or .co.il!\n";

    //initiate properties
    account.accountNumber = _accountNumber;
    account.code = _code;
    account.email = _email;
    return inStream;
}

// active if account draw some cash from bank
//able to draw up to 2500 nis and credit up to 6000 nis
void Account::withdraw(float nis) {
    if ((float)balance - nis < -6000)//checking credit usage
        throw "ERROR: cannot have less than - 6000 NIS!\n";
    if (nis > 2500)//checking requested value to draw
        throw "ERROR: cannot withdraw more than 2500 NIS!\n";
    balance -= nis;// decrease value of available nis in 'this' account
    sumWithdraw++;// counting up draws
}

void Account::deposit(float nis) {// deposit checks in this account - able to deposit op to 10000 nis
    if (nis > 10000)//checking requested value to deposit
        throw "ERROR: cannot deposit more than 10000 NIS!\n";
    balance += nis;// increase value of available nis in 'this' account as it deposit new check
    sumDeposit++;// counting up deposits
}

int Account::getSumWithdraw() {
    return sumWithdraw;
}

int Account::getSumDeposit() {
    return sumDeposit;
}
