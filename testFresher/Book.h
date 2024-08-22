#include <iostream>
#include <stdio.h>
#include <string>
using namespace std; 
// Book.h
#ifndef BOOK_H
#define BOOK_H


class Book {
private:
    string id;
    string title;
    string author;
    string category;
    int yearPublished;
    bool isAvailable;

public:
    // Constructor
    Book() = default;
    Book(string id, string title, string author, string genre, int yearPublished, bool isAvailable);

    // Getter and Setter functions
    string getId() const;
    void setId(const string& id);

    string getTitle() const;
    void setTitle(const string& title);

    string getAuthor() const;
    void setAuthor(const string& author);

    string getCategory() const;
    void setCategory(const string& genre);

    int getYearPublished() const;
    void setYearPublished(int year);

    bool getAvailability() const;
    void setAvailability(bool isAvailable);

    void print() const;
};

#endif // BOOK_H
