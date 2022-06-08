/***********************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482 *
 * cpp lab - Meir Litman                                   *
 * exercise 9 task 2                                       *
 * class header represent books in library                 *
************************************************************/
#ifndef HELLOCPPLAB1_BOOK_H
#define HELLOCPPLAB1_BOOK_H
#include <string>
#include <iostream>

using namespace std;
class Book {
public:
    Book(int bid, const string &author, const string &name);//ctor
    Book();//empt ctor

    int getBid() const;

    void setBid(int bid);

    const string &getAuthor() const;

    void setAuthor(const string &author);

    const string &getName() const;

    void setName(const string &name);

    bool operator==(const Book &rhs) const;

    bool operator!=(const Book &rhs) const;

    bool operator<(const Book &rhs) const;

    bool operator>(const Book &rhs) const;

    bool operator<=(const Book &rhs) const;

    bool operator>=(const Book &rhs) const;

    friend ostream &operator<<(ostream &os, const Book &book);
    friend istream &operator>>(istream &is, Book &book);

private:
    Book bid;
    string author;
    string name;

};


#endif //HELLOCPPLAB1_BOOK_H
