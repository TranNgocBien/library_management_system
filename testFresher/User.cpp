// User.cpp
#include "User.h"
#include <algorithm>
#include <vector>
// Constructor
User::User(string id, string name, string email, string phoneNumber)
    : id(id), name(name), email(email), phoneNumber(phoneNumber)   {}

// Getter and Setter functions
string User::getId() const {
    return id;
}

void User::setId(const string& id) {
    this->id = id;
}

string User::getName() const {
    return name;
}

void User::setName(const string& name) {
    this->name = name;
}

string User::getEmail() const {
    return email;
}

void User::setEmail(const string& email) {
    this->email = email;
}

string User::getPhoneNumber() const {
    return phoneNumber;
}

void User::setPhoneNumber(const string& phoneNumber) {
    this->phoneNumber = phoneNumber;
}

vector<string> User::getBorrowedBooks() const { 
    return borrowedBooks; 
}

void User::addBorrowedBook(const string& bookId) { 
    borrowedBooks.push_back(bookId); 
}

void User::removeBorrowedBook(const string& bookId) {
    borrowedBooks.erase(remove(borrowedBooks.begin(), borrowedBooks.end(), bookId), borrowedBooks.end());
}

void User::print() const {
    cout << "ID: " << id << ", Name: " << name << ", Email: " << email
                  << ", Phone: " << phoneNumber << endl;
    cout << "Borrowed Books: ";
        for (const auto& bookId : borrowedBooks) {
            cout << bookId << " ";
        }
    cout << endl;
}

