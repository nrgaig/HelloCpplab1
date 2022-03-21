//
// Created by itayo on 21/03/2022.
//

#ifndef HELLOCPPLAB1_ACCOUNT_H
#define HELLOCPPLAB1_ACCOUNT_H

#include <string>

using namespace std;


class Account {
private:
    int accountNumber;
    int code;
    int balance;
    string email;

public:


    Account();

    Account(int _accountNumber, int _code, int _balance, string _email);

    int getAccountNumber() const;

    int getCode() const;

    int getBalance() const;

    const string &getEmail() const;

    friend istream& operator>>(istream& is, Account& ms);// istream operator

    void withdraw(int nis);

    void deposit(int nis);
    static int sumWithdraw;
    static int sumDeposit ;

    static int getSumWithdraw();

    static int getSumDeposit();
};


#endif //HELLOCPPLAB1_ACCOUNT_H
