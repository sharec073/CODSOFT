//TASK 5: LIBRARY MANAGEMENT SYSTEM
#include <iostream>
#include <iomanip>  // Header file to add setprecision
#include <cstring>
#include <ctime>
using namespace std;
const int MAX_BOOKS = 100;
const int MAX_BORROWERS = 50;
const int MAX_BORROWED_BOOKS = 5;
struct Book {
    char title[100];
    char author[100];
    char ISBN[20];
    bool available;
};
struct Borrower {
    char name[100];
    Book* borrowedBooks[MAX_BORROWED_BOOKS];
    time_t dueDates[MAX_BORROWED_BOOKS];
    int numBorrowedBooks;
};
//Create a class to include all functions
class Library {
private:
    Book books[MAX_BOOKS];
    Borrower borrowers[MAX_BORROWERS];
    int numBooks;
    int numBorrowers;
public:
    Library() : numBooks(0), numBorrowers(0) {}
    //Function to add books to the library
    void addBook(const char* title, const char* author, const char* ISBN) {
        if (numBooks < MAX_BOOKS) {
            Book newBook;
            strcpy(newBook.title, title);
            strcpy(newBook.author, author);
            strcpy(newBook.ISBN, ISBN);
            newBook.available = true;
            books[numBooks++] = newBook;
            cout << "Book added successfully.\n";
        } else {
            cout << "Cannot add more books. Library is full.\n";
        }
    }
    //Function to display books available in the library
    void displayBooks() {
        cout << "Books in the Library:\n";
        for (int i = 0; i < numBooks; ++i) {
            cout << "Title: " << books[i].title << "\tAuthor: " << books[i].author
                 << "\tISBN: " << books[i].ISBN << "\tAvailable: " << (books[i].available ? "Yes" : "No") << "\n";
        }
    }
    //Function to search the book from the list of books available
    Book* searchBook(const char* searchKey) {
        for (int i = 0; i < numBooks; ++i) {
            if (strcmp(books[i].title, searchKey) == 0 ||
                strcmp(books[i].author, searchKey) == 0 ||
                strcmp(books[i].ISBN, searchKey) == 0) {
                return &books[i];
            }
        }
        return nullptr;
    }
    //Function to check out the specific book from the list of books available
    void checkOutBook(Borrower& borrower, Book* book, time_t dueDate) {
        if (book && book->available && borrower.numBorrowedBooks < MAX_BORROWED_BOOKS) {
            book->available = false;
            borrower.borrowedBooks[borrower.numBorrowedBooks] = book;
            borrower.dueDates[borrower.numBorrowedBooks++] = dueDate;
            cout << "Book checked out successfully.\n";
        } else {
            cout << "Book not available for checkout or borrower has reached the limit.\n";
        }
    }
    //Function to return the book borrowed from the library
    void returnBook(Borrower& borrower, Book* book) {
        for (int i = 0; i < borrower.numBorrowedBooks; ++i) {
            if (borrower.borrowedBooks[i] == book) {
                time_t currentTime;
                time(&currentTime);
                if (currentTime > borrower.dueDates[i]) {
                    int daysOverdue = static_cast<int>((currentTime - borrower.dueDates[i]) / (60 * 60 * 24));
                    cout << "Book is overdue by " << daysOverdue << " days.\n";
                    float fine = 0.5 * daysOverdue; 
                    cout << "Fine: $" << fixed << setprecision(2) << fine << "\n";
                }
                book->available = true;
                borrower.borrowedBooks[i] = nullptr;
                borrower.dueDates[i] = 0;
                cout << "Book returned successfully.\n";
                return;
            }
        }
        cout << "Book not found in the borrower's records.\n";
    }
};
//Main Function
int main() {
    Library library;
    //Adding some books into the library
    library.addBook("The Catcher in the Rye", "J.D. Salinger", "978-0-316-76948-0");
    library.addBook("To Kill a Mockingbird", "Harper Lee", "978-0-06-112008-4");
    library.addBook("The Water Dancer", "Ta-Nehisi Coates", "978-0-525-52024-5");
    library.addBook("1984", "George Orwell", "978-0-452-28423-4");
    library.addBook("Educated", "Tara Westover", "978-0-399-59050-4");
    library.addBook("Circle", "Madeline Miller", "978-0-316-55634-7");
    library.addBook("Becoming", "Michelle Obama", "978-1-5247-6313-8");
    library.addBook("The Dutch House", "Ann Patchett", "978-0-062-62502-9");
    library.addBook("he Silent Patient", "Alex Michaelides", "978-1-250-30169-7");
    library.addBook("Sapiens: A Brief History of Humankind", "Yuval Noah Harari", "978-0-06-231611-0");
    Borrower borrower;
    strcpy(borrower.name, "John Doe");
    borrower.numBorrowedBooks = 0;
    while (true) {
        //Getting input from the user
        cout << "\n-----Library Management System-----\n";
        cout << "1. Display Books\n";
        cout << "2. Search for a Book\n";
        cout << "3. Check Out a Book\n";
        cout << "4. Return a Book\n";
        cout << "5. Exit\n";
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
            //To display the books stored in the library
                library.displayBooks();
                break;
            case 2: {
            //To search for a book in the library
                char searchKey[100];
                cout << "Enter search key (title, author, or ISBN): ";
                cin.ignore();
                cin.getline(searchKey, sizeof(searchKey));
                Book* foundBook = library.searchBook(searchKey);
                if (foundBook) {
                    cout << "Book found:\n";
                    cout << "Title: " << foundBook->title << "\tAuthor: " << foundBook->author
                         << "\tISBN: " << foundBook->ISBN << "\tAvailable: " << (foundBook->available ? "Yes" : "No") << "\n";
                } else {
                    cout << "Book not found.\n";
                }
                break;
            }
            case 3: {
            //To check out a book from the library
                char searchKey[100];
                cout << "Enter search key to check out a book (title, author, or ISBN): ";
                cin.ignore();
                cin.getline(searchKey, sizeof(searchKey));
                time_t now = time(0);
                //Fixing due date and calculating fine amount
                time_t dueDate = now + 14 * 24 * 60 * 60; 
                Book* foundBook = library.searchBook(searchKey);
                library.checkOutBook(borrower, foundBook, dueDate);
                break;
            }
            case 4: {
            //To return the borrowed book from the library
                char searchKey[100];
                cout << "Enter search key to return a book (title, author, or ISBN): ";
                cin.ignore();
                cin.getline(searchKey, sizeof(searchKey));
                Book* foundBook = library.searchBook(searchKey);
                library.returnBook(borrower, foundBook);
                break;
            }
            case 5:
            //To exit from the program
                cout << "Thank You....\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}