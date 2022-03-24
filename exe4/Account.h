/****************************************************
  Created by Maor Frost 206370231 and Itay Oren 318648482
  cpp lab - Meir Litman
  exercise 4
  class header implementing bank account to mange
****************************************************/

#ifndef HELLOCPPLAB1_ACCOUNT_H
#define HELLOCPPLAB1_ACCOUNT_H

#include <string>

using namespace std;


class Account {
private:
    int accountNumber;
    int code;// length of 4 digs and left dig not '0'
    int balance;
    string email;// username@domain.locale = valid email
    static int sumWithdraw; // static - counter of all draws of this account
    static int sumDeposit ; // static - counter of all deposits of this account

public:


    Account();//empty constructor

    Account(int _accountNumber, int _code, int _balance, const string& _email);//constructor

    int getAccountNumber() const;

    int getCode() const;

    int getBalance() const;

    const string &getEmail() const;

    friend istream& operator>>(istream& is, Account& ms);// istream operator

    void withdraw(float nis);// active if account draw some cash from bank able to draw up to 2500 nis and credit up to 6000 nis

    void deposit(float nis);// deposit checks in this account - able to deposit op to 10000 nis

    static int getSumWithdraw();

    static int getSumDeposit();
};


#endif //HELLOCPPLAB1_ACCOUNT_H
