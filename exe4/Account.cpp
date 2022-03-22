//
// Created by itayo on 21/03/2022.
//

#include "Account.h"
#include <iostream>

using namespace std;

int Account::sumWithdraw = 0;
int Account::sumDeposit = 0;


Account::Account() : accountNumber(0), code(0), balance(0), email("") {} // empty constructor

Account::Account(int _accountNumber, int _code, int _balance, string _email) {
    if (_code < 1000)
        throw "ERROR: code must be of 4 digits!\n";

    size_t locationOfShtrudel = _email.find('@');
    if (locationOfShtrudel == string::npos)
        throw "ERROR: email must contain @!\n";

    if (_email.find(".co.il", locationOfShtrudel + 1) == string::npos &&
        _email.find(".com", locationOfShtrudel + 1) == string::npos)
        throw "ERROR: email must end at .com or .co.il!\n";
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

istream &operator>>(istream &is, Account &ms) {
    int _accountNumber, _code;
    string _email;
    is >> _accountNumber >> _code >> _email;
    if (_code < 1000)
        throw "ERROR: code must be of 4 digits!\n";
    size_t locationOfShtrudel = _email.find('@');
    if (locationOfShtrudel == string::npos)
        throw "ERROR: email must contain @!\n";
    size_t locationOfCom = _email.find(".com", locationOfShtrudel + 1);
    size_t locationOfComIl = _email.find(".co,il", locationOfShtrudel + 1);
    if (locationOfComIl == string::npos && locationOfCom == string::npos)
        throw "ERROR: email must end at .com or .co.il!\n";
    ms.accountNumber = _accountNumber;
    ms.code = _code;
    ms.email = _email;
    return is;
}


void Account::withdraw(int nis) {
    if (balance - nis < -6000)
        throw "ERROR: cannot have less than - 6000 NIS!\n";
    if (nis > 2500)
        throw "ERROR: cannot withdraw more than 2500 NIS!\n";
    balance -= nis;
}

void Account::deposit(int nis) {
    if (nis > 10000)
        throw "ERROR: cannot deposit more than 10000 NIS!\n";
    balance += nis;
}

int Account::getSumWithdraw() {
    return sumWithdraw;
}

int Account::getSumDeposit() {
    return sumDeposit;
}