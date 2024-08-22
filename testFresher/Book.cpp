#include "Book.h"

// Constructor
Book::Book(string id, string title, string author, string genre, int yearPublished, bool isAvailable)
    : id(id), title(title), author(author), category(category), yearPublished(yearPublished), isAvailable(isAvailable) {}

// Getter and Setter functions
string Book::getId() const {
    return id;
}

void Book::setId(const string& id) {
    this->id = id;
}

string Book::getTitle() const {
    return title;
}

void Book::setTitle(const string& title) {
    this->title = title;
}

string Book::getAuthor() const {
    return author;
}

void Book::setAuthor(const string& author) {
    this->author = author;
}

string Book::getCategory() const {
    return category;
}

void Book::setCategory(const string& category) {
    this->category = category;
}

int Book::getYearPublished() const {
    return yearPublished;
}

void Book::setYearPublished(int year) {
    this->yearPublished = year;
}

bool Book::getAvailability() const {
    return isAvailable;
}

void Book::setAvailability(bool isAvailable) {
    this->isAvailable = isAvailable;
}

// tostring
void Book::print() const {
    cout << "ID: " << id << ", Title: " << title << ", Author: " << author
                  << ", Genre: " << category << ", YearPublished: " << yearPublished
                  << ", Status: " << (isAvailable ? "Available" : "Borrowed") << endl;
}
