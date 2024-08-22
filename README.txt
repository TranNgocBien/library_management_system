===============================================Library Management System==========================================
I.Project Description
    The Library Management System helps manage book information, users, and book borrowing/returning activities. 
    The system provides functionalities for adding, removing, and updating books, searching for books, borrowing and returning books, 
    and generating reports.

II.Key Features
    1,Book Management:
        Add, remove, and update book information.
        Search for books by title, author, or category.
        List all books with detailed information and current status.
    2,User Management:
        Add, remove, and update user information.
        List all users and the books they have borrowed.
    3,Borrowing and Returning Books:

        Users can borrow and return books.
        Update the book status when borrowed or returned.
    4,Reports:
        Report the most borrowed books.
        Report the list of books that have been borrowed but not returned for more than 30 days.

    5,Technical Requirements
        Language: C++
        Library: STL (Standard Template Library)
        Data Storage: Text files (.txt)

III.Installation Instructions
    1,Set Up Development Environment:
        Install a C++ compiler such as GCC or MSVC.
        Install an IDE like Visual Studio, Code::Blocks, or use a command-line compiler.
    2,Create Source Files:
        Create .cpp and .h files for the Book, User, LibrarySystem classes, and related functions.
        Example files: Book.h, Book.cpp, User.h, User.cpp, LibrarySystem.h, LibrarySystem.cpp, and main.cpp.
    3,Compile the Project:
        Use the compiler to compile all source files into an executable program.
        Example compile command (GCC):
            g++ main.cpp Library.cpp Book.cpp User.cpp -o a
            ./a
    4,Run the Program:
        After successful compilation, run the executable to use the library management system.

IV.Usage Instructions
    1,Start the Program:
        Run the compiled executable.
    2,Interact with the System:
        The program will display a menu with the following options:
            1. Borrow a Book: Enter user ID and book ID to borrow.
            2. Return a Book: Enter user ID and book ID to return.
            3. Search Books: Enter a search keyword to find books by title, author, or category.
            4. List All Books: Display all books currently in the library.
            5. List All Users: Display all users and the books they have borrowed.
            6. Report Most Borrowed Books: Show the most borrowed books.
            7. Report Overdue Books: Show the list of books borrowed but not returned for more than 30 days.
            8. Exit: Exit the program.
    3,Input Data:
        Books: The file books.txt contains book information in the following format:
            bookId,title,author,category,year,status
        Example:
            book001,The Great Gatsby,F. Scott Fitzgerald,Fiction,1925,Available
        Users: The file users.txt contains user information in the following format:
            userId,name,email,phoneNumber
        Example:
            user001,John Doe,john.doe@example.com,123-456-7890
    4,Notes:
        Ensure that the data files (books.txt and users.txt) are located 
        in the current working directory of the program or provide the correct path to these files.

V.Explanation of Design Choices
    1,Object-Oriented Design: Encapsulation and abstraction help in managing complexity and enhancing maintainability. 
    Books and users are modeled as objects with relevant attributes and behaviors.

    2,STL Containers: std::map is chosen for storing books and users due to its efficient key-based access. 
    This ensures quick lookups and insertions.

    3,File I/O: Simple text files are used for data persistence. 
    This choice simplifies implementation but can be replaced with a more robust database solution if needed.