#include <stdio.h>
#include <map>
#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include "User.h"
#include "Book.h"
#ifndef LIBRARY_H
#define LIBRARY_H
class Library {
private:
    // vector<Book> books;
    // vector<User> users;
    map<string, Book> books;
    map<string, User> users;

public:
    
    // Add a book to the library
    void addBook(const Book& book);
    
    // Add a user to the system
    void addUser(const User& user);

    // Borrow book
    void borrowBook(const string& userId, const string& bookId);

    // Return book
    void returnBook(const string& userId, const string& bookId);

    // Search for book
    void searchBooks(const string& keyword) const;  

    // List all books
    void listBooks() const;

    // List all users and borrowed books
    void listUsers() const;

    // Report the most borrowed books
    void reportMostBorrowedBooks() const;

    // Report books borrowed for more than 30 days
    void reportOverdueBooks() const;

    // Save books to a file
    void saveBooksToFile(const string& filename) const;

    // Save users to a file
    void saveUsersToFile(const string& filename) const;

    // Load books from a file
    void loadBooksFromFile(const string& filename, map<string, Book>& books);

    // Load users from a file
    void loadUsersFromFile(const string& filename, map<string, User>& users);
};
#endif // LIBRARY_H