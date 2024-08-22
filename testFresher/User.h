#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "Book.h"
using namespace std;
#ifndef USER_H
#define USER_H

class User
{
private:
    string id;
    string name;
    string email;
    string phoneNumber;
    vector<string> borrowedBooks;

public:
    // Constructor
    User() = default;
    User(string id, string name, string email, string phoneNumber);

    // Getter and Setter functions
    string getId() const;
    void setId(const string &id);

    string getName() const;
    void setName(const string &name);

    string getEmail() const;
    void setEmail(const string &email);

    string getPhoneNumber() const;
    void setPhoneNumber(const string &phoneNumber);

    vector<string> getBorrowedBooks() const;

    // add a book ID to the list of books that the user has borrowed.
    void addBorrowedBook(const string &bookId);

    // remove a book ID from the list of books borrowed by the user
    void removeBorrowedBook(const string &bookId);

    void print() const;
};

#endif // USER_H
