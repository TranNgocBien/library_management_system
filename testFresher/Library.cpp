// Library.cpp
#include "Library.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <ctime>

// Hàm thêm sách vào thư viện
void Library::addBook(const Book &book)
{
    books[book.getId()] = book;
}

// Hàm thêm người dùng vào hệ thống
void Library::addUser(const User &user)
{
    users[user.getId()] = user;
}

void Library::borrowBook(const string &userId, const string &bookId)
{
    if (books.find(bookId) == books.end() || users.find(userId) == users.end())
    {
        throw invalid_argument("Book or User ID not found");
    }
    if (!books[bookId].getAvailability())
    {
        throw runtime_error("Book is already borrowed");
    }

    books[bookId].setAvailability(false);
    users[userId].addBorrowedBook(bookId);
}

void Library::returnBook(const string &userId, const string &bookId)
{
    if (books.find(bookId) == books.end() || users.find(userId) == users.end())
    {
        throw invalid_argument("Book or User ID not found");
    }
    if (books[bookId].getAvailability())
    {
        throw runtime_error("Book was not borrowed");
    }

    books[bookId].setAvailability(true);
    users[userId].removeBorrowedBook(bookId);
}

void Library::searchBooks(const string &keyword) const
{
    for (const auto &[id, book] : books)
    {
        if (book.getTitle().find(keyword) != string::npos ||
            book.getAuthor().find(keyword) != string::npos ||
            book.getCategory().find(keyword) != string::npos)
        {
            book.print();
        }
    }
}

void Library::listBooks() const
{
    for (const auto &[id, book] : books)
    {
        book.print();
    }
}

void Library::listUsers() const
{
    for (const auto &[id, user] : users)
    {
        user.print();
    }
}

void Library::reportMostBorrowedBooks() const
{
    map<string, int> bookBorrowCount;
    
    // Count the number of times each book is borrowed
    for (const auto& userPair : users) {
        const User& user = userPair.second;
        vector<string> borrowedBooks = user.getBorrowedBooks();
        for (const string& bookId : borrowedBooks) {
            bookBorrowCount[bookId]++;
        }
    }

    // Convert `bookBorrowCount` to vector for sorting
    vector<pair<string, int>> sortedBookBorrowCount(bookBorrowCount.begin(), bookBorrowCount.end());

    // Sort by number of times borrowed (descending)
    sort(sortedBookBorrowCount.begin(), sortedBookBorrowCount.end(), 
              [](const pair<string, int>& a, const pair<string, int>& b) {
                  return a.second > b.second;
              });

    // Display the report
    cout << "Most Borrowed Books Report:" << endl;
    for (const auto& pair : sortedBookBorrowCount) {
        const string& bookId = pair.first;
        int count = pair.second;
        auto it = books.find(bookId);
        if (it != books.end()) {
            const Book& book = it->second;
            cout << "Book ID: " << book.getId() << ", Title: " << book.getTitle() << ", Borrowed: " << count << " times" << endl;
        }
    }
}

void Library::reportOverdueBooks() const
{
    //not done
}

void Library::saveBooksToFile(const string& filename) const {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }

    for (const auto& [id, book] : books) {
        file << id << ","
             << book.getTitle() << ","
             << book.getAuthor() << ","
             << book.getCategory() << ","
             << book.getYearPublished() << ","
             << (book.getAvailability() ? "Available" : "Borrowed") << endl;
    }
}

void Library::saveUsersToFile(const string& filename) const {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }

    for (const auto& [id, user] : users) {
        file << id << ","
             << user.getName() << ","
             << user.getEmail() << ","
             << user.getPhoneNumber() << endl;

        for (const auto& bookId : user.getBorrowedBooks()) {
            file << bookId << " ";
        }
        file << endl;
    }
}

void Library::loadBooksFromFile(const string& filename, map<string, Book>& books) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream ss(line);
        string id, title, author, category, status;
        int year;

        getline(ss, id, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, category, ',');
        ss >> year;
        ss.ignore(); // Ignore the comma after year
        getline(ss, status);

        bool isAvailable = (status == "Available");
        books[id] = Book(id, title, author, category, year, isAvailable);
    }
}

    void Library::loadUsersFromFile(const string& filename, map<string, User>& users) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream ss(line);
        string id, name, email, phoneNumber;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, email, ',');
        getline(ss, phoneNumber);

        users[id] = User(id, name, email, phoneNumber);

        // Read borrowed books
        getline(file, line); // Read the next line with borrowed books
        istringstream borrowedBooksStream(line);
        string bookId;
        while (borrowedBooksStream >> bookId) {
            users[id].addBorrowedBook(bookId);
        }
    }
}
