#include <iostream>
#include <chrono>
#include <thread>
#include <map>
#include <string>
#include "Library.h"
#include "Book.h"
#include "User.h"

void displayMenu()
{
    cout << "\nLibrary Management System" << endl;
    cout << "1. Borrow a book" << endl;
    cout << "2. Return a book" << endl;
    cout << "3. Search books" << endl;
    cout << "4. List all books" << endl;
    cout << "5. List all users" << endl;
    cout << "6. Report most borrowed books" << endl;
    cout << "7. Report overdue books" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    Library library;

    map<string, Book> books;
    map<string, User> users;

    library.loadBooksFromFile("demo_C++\\books.txt", books);
    library.loadUsersFromFile("demmo_C++\\people.txt", users);

    int choice;
    string userId, bookId;
    string keyword;
    while (true)
    {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1: 
            cout << "Enter User ID: ";
            getline(cin, userId);
            cout << "Enter Book ID: ";
            getline(cin, bookId);
            try
            {
                library.borrowBook(userId, bookId);
                cout << "Book borrowed successfully!" << endl;
            }
            catch (const exception &e)
            {
                cerr << e.what() << endl;
            }
            break;

        case 2: 
            cout << "Enter User ID: ";
            getline(cin, userId);
            cout << "Enter Book ID: ";
            getline(cin, bookId);
            try
            {
                library.returnBook(userId, bookId);
                cout << "Book returned successfully!" << endl;
            }
            catch (const exception &e)
            {
                cerr << e.what() << endl;
            }
            break;

        case 3: 

            cout << "Enter search keyword (Title/Author/Category): ";
            getline(cin, keyword);
            library.searchBooks(keyword);
            break;

        case 4: 
            library.listBooks();
            break;

        case 5: 
            library.listUsers();
            break;

        case 6: 
            library.reportMostBorrowedBooks();
            break;

        case 7: 
            library.reportOverdueBooks();
            break;

        case 8: 
            cout << "Exiting program." << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
