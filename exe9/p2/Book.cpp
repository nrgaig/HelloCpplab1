/***********************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482 *
 * cpp lab - Meir Litman                                   *
 * exercise 9 task 2                                       *
 * class implement books in library                        *
************************************************************/
#include "Book.h"
using namespace std;

int Book::getBid() const {
    return bid;
}

void Book::setBid(int bid) {
    Book::bid = bid;
}

const string &Book::getAuthor() const {
    return author;
}

void Book::setAuthor(const string &author) {
    Book::author = author;
}

const string &Book::getName() const {
    return name;
}

void Book::setName(const string &name) {
    Book::name = name;
}

Book::Book(int bid, const string &author, const string &name) : bid(bid), author(author), name(name) {}//ctor

Book::Book() : bid(0), author(""), name("") {}//emp ctor

bool Book::operator==(const Book &rhs) const {
    return author == rhs.author && name == rhs.name && bid == rhs.bid;
}

bool Book::operator!=(const Book &rhs) const {
    return !(rhs == *this);
}

bool Book::operator<(const Book &rhs) const {
    if (author < rhs.author)
        return true;
    if (rhs.author < author)
        return false;
    if (name < rhs.name)
        return true;
    if (rhs.name < name)
        return false;
    return bid < rhs.bid;
}

bool Book::operator>(const Book &rhs) const {
    return rhs < *this;
}

bool Book::operator<=(const Book &rhs) const {
    return !(rhs < *this);
}

bool Book::operator>=(const Book &rhs) const {
    return !(*this < rhs);
}

ostream &operator<<(ostream &os, const Book &book) {
    os << book.bid << book.author << book.name << "\n";
    return os;
}

istream &operator>>(istream &is, Book &book) {
    is >> book.bid >> book.author >> book.name;
    return is;
}

