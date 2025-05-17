#include <iostream>
using namespace std;

const int MAX_BOOKS = 100;

struct Book {
    string title;
    string author;
    string isbn;
    bool isAvailable;
};

Book books[MAX_BOOKS];
int count = 0;

void addBook() {
    if (count >= MAX_BOOKS) {
        cout << "Library is full.\n";
        return;
    }
    cout << "Enter title: ";
    cin.ignore();
    getline(cin, books[count].title);
    cout << "Enter author: ";
    getline(cin, books[count].author);
    cout << "Enter ISBN: ";
    getline(cin, books[count].isbn);
    books[count].isAvailable = true;
    count++;
    cout << "Book added.\n";
}

void viewBooks() {
    if (count == 0) {
        cout << "No books in library.\n";
        return;
    }
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << books[i].title << " by " << books[i].author;
        cout << " | ISBN: " << books[i].isbn << " | ";
        cout << (books[i].isAvailable ? "Available" : "Checked Out") << "\n";
    }
}

void searchBook() {
    string term;
    cout << "Enter title/author/ISBN to search: ";
    cin.ignore();
    getline(cin, term);

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (books[i].title == term || books[i].author == term || books[i].isbn == term) {
            cout << books[i].title << " by " << books[i].author << " | ISBN: " << books[i].isbn;
            cout << " | " << (books[i].isAvailable ? "Available" : "Checked Out") << "\n";
            found = true;
        }
    }
    if (!found) cout << "No book found.\n";
}

void checkoutBook() {
    string isbn;
    cout << "Enter ISBN to check out: ";
    cin.ignore();
    getline(cin, isbn);
    for (int i = 0; i < count; i++) {
        if (books[i].isbn == isbn) {
            if (!books[i].isAvailable) {
                cout << "Book is already checked out.\n";
                return;
            }
            books[i].isAvailable = false;
            cout << "Book checked out.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void returnBook() {
    string isbn;
    cout << "Enter ISBN to return: ";
    cin.ignore();
    getline(cin, isbn);
    for (int i = 0; i < count; i++) {
        if (books[i].isbn == isbn) {
            if (books[i].isAvailable) {
                cout << "Book was not checked out.\n";
                return;
            }
            books[i].isAvailable = true;
            cout << "Book returned.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

int main() {
    int choice;
    while (true) {
        cout << "\n?? LIBRARY MANAGEMENT SYSTEM\n";
        cout << "1. Add Book\n2. View Books\n3. Search Book\n4. Check Out\n5. Return\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) addBook();
        else if (choice == 2) viewBooks();
        else if (choice == 3) searchBook();
        else if (choice == 4) checkoutBook();
        else if (choice == 5) returnBook();
        else if (choice == 6) break;
        else cout << "Invalid choice.\n";
    }
    return 0;
}

