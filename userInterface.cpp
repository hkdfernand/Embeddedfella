// user interface.cpp
// copyright Muhammed salim & Fernand Havugimana
// Author Fernand Havugimana
#include <iostream>
#include <vector>
#include <algorithm>
#include "Book.h"
#include "member.h"
#include "borrow.h"
#include "report.h"
#include "LibraryItem.h"

using namespace std;

// Function declarations
void addBook(vector<Book>& books);
void deleteBook(vector<Book>& books);
void editBook(vector<Book>& books);
void searchBook(const vector<Book>& books);
void addMember(vector<Member>& members);
void deleteMember(vector<Member>& members);
void editMember(vector<Member>& members);
void searchMember(const vector<Member>& members);
void borrowBook(const vector<Book>& books, vector<Member>& members, vector<Borrow>& borrows);
void returnBook(vector<Member>& members, vector<Borrow>& borrows);
void generateReport(const vector<Book>& books, const vector<Member>& members, const vector<Borrow>& borrows);

int main() {
    vector<Book> books;
    vector<Member> members;
    vector<Borrow> borrows;
    int choice = 0;
    while (choice != 9) {
        // Menu
        cout << "========== Library Management System Menu ==========" << endl;
        cout << "1. Add book" << endl;
        cout << "2. Delete book" << endl;
        cout << "3. Edit book" << endl;
        cout << "4. Search book" << endl;
        cout << "5. Add member" << endl;
        cout << "6. Delete member" << endl;
        cout << "7. Edit member" << endl;
        cout << "8. Search member" << endl;
        cout << "9. Borrow book" << endl;
        cout << "10. Return book" << endl;
        cout << "11. Generate report" << endl;
        cout << "12. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            addBook(books);
            break;
        case 2:
            deleteBook(books);
            break;
        case 3:
            editBook(books);
            break;
        case 4:
            searchBook(books);
            break;
        case 5:
            addMember(members);
            break;
        case 6:
            deleteMember(members);
            break;
        case 7:
            editMember(members);
            break;
        case 8:
            searchMember(members);
            break;
        case 9:
            borrowBook(books, members, borrows);
            break;
        case 10:
            returnBook(members, borrows);
            break;
        case 11:
            generateReport(books, members, borrows);
            break;
        case 12:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
        cout << endl;
    }
    return 0;
}

void addBook(vector<Book>& books) {
    string title, author, publisher, ISBN, BookID;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter author name: ";
    getline(cin, author);
    cout << "Enter publisher name: ";
    getline(cin, publisher);
    cout << "Enter ISBN: ";
    getline(cin, ISBN);
    cout << "Enter book ID: ";
    getline(cin, BookID);
    Book book(title, author, publisher, ISBN, BookID);
    books.push_back(book);
    cout << "Book added successfully" << endl;
}

void deleteBook(vector<Book>& books) {
    string title, author, publisher, bookID;
    cout << "Enter book ID: ";
    cin.ignore();
    getline(cin, bookID);
    auto it = find_if(books.begin(), books.end(),
        [bookID](const Book& book)
        {
            return book.getBookID() == bookID;
        });
    if (it != books.end()) {
        books.erase(it);
        cout << "Book deleted successfully" << endl;
    }
    else {
        cout << "Book not found" << endl;
    }
}
void editBook(vector<Book>& books)
{
    string bookID;
    cout << "Enter book ID: ";
    cin.ignore();
    getline(cin, bookID);
    auto it = find_if(books.begin(), books.end(),
        [bookID](const Book& book) {
            return book.getBookID() == bookID;
        });
    if (it != books.end()) {
        string title, author, publisher, ISBN;
        cout << "Enter new book title (leave blank to keep existing value): ";
        cin.ignore();
        getline(cin, title);
        if (!title.empty()) {
            it->setTitle(title);
        }
        cout << "Enter new author name (leave blank to keep existing value): ";
        getline(cin, author);
        if (!author.empty()) {
            it->setAuthor(author);
        }
        cout << "Enter new publisher name (leave blank to keep existing value): ";
        getline(cin, publisher);
        if (!publisher.empty()) {
            it->setPublisher(publisher);
        }
        cout << "Enter new ISBN (leave blank to keep existing value): ";
        getline(cin, ISBN);
        if (!ISBN.empty()) {
            it->setISBN(ISBN);
        }
        cout << "Book edited successfully" << endl;
    }
    else {
        cout << "Book not found" << endl;
    }
}
void searchBook(const vector<Book>& books)
{
    string query;
    cout << "Enter search query: ";
    cin >> query;
    vector<Book> results; // vector declaration to store search results
    for (const auto& book : books) /*Iterates through each "Book" object in a collection named "books"*/
    {
        /*Checks if the search query appears in any of the book's properties such as title, author, publisher, ISBN or BookID. If so, the book is added to the results vector*/
        if (book.getTitle().find(query) != string::npos || book.getAuthor().find(query) != string::npos || book.getPublisher().find(query) != string::npos || book.getISBN().find(query) != string::npos || book.getBookID().find(query) != string::npos)
        {
            results.push_back(book);
        }
    }
    if (results.empty())
    {
        cout << "No books found" << endl;
    }
    else {
        cout << "Search results: " << endl;
        for (const auto& book : results)
        {
            book.display();
        }
    }
}
void addMember(vector<Member>& members) {
    string name, contactInformation, memberID;
    cout << "Enter Member name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter member ID: ";
    getline(cin, memberID);
    cout << "Enter member contact information: ";
    getline(cin, contactInformation);
    Member member(name, contactInformation, memberID);
    members.push_back(member);
    cout << "Book added successfully" << endl;
}
void deleteMember(vector<Member>& members)
{
    string memberID;
    cout << "Enter member ID: ";
    cin.ignore();
    getline(cin, memberID);
    auto it = find_if(members.begin(), members.end(), [memberID](const Member& member) { return member.getMemberID() == memberID; });
    if (it != members.end())
    {
        members.erase(it);
        cout << "member deleted successfully" << endl;
    }
    else
    {
        cout << "member not found" << endl;
    }
}
void editMember(vector<Member>& members)
{
    string name, contactInformation, memberID;
    cout << "Enter name to edit: ";
    cin.ignore();
    getline(cin, name);
    auto it = find_if(members.begin(), members.end(),
        [name](const Member& member) {
            return member.getName() == name;
        });
    if (it != members.end()) {
        string name, contactInformation, memberID;
        cout << "Edit name : ";
        cin.ignore();
        getline(cin, name);
        if (!name.empty()) {
            it->setName(name);
        }
        cout << "Edit contact information: ";
        getline(cin, contactInformation);
        if (!contactInformation.empty()) {
            it->setContactInformation(contactInformation);
        }
        cout << "Edit member ID: ";
        getline(cin, memberID);
        if (!memberID.empty()) {
            it->setMemberID(memberID);
        }
        cout << "member edited successfully" << endl;
    }
    else {
        cout << "member not edited try again " << endl;
    }
}
void searchMember(const vector<Member>& members)
{
    string query;
    cout << "Enter search query: ";
    cin >> query;
    vector<Member> results;
    for (const auto& member : members)
    {
        if (member.getName().find(query) != string::npos || member.getContactInformation().find(query) != string::npos || member.getMemberID().find(query) != string::npos)
        {
            results.push_back(member);
        }
    }
    if (results.empty())
    {
        cout << "No member found" << endl;
    }
    else {
        cout << "Search results: " << endl;
        for (const auto& member : results) {
            member.display();
        }
    }
}
void borrowBook(const vector<Book>& books, vector<Member>& members, vector<Borrow>& borrows) {
    string bookID, memberID;
    cout << "Enter book ID to be borrowed: ";
    cin.ignore();
    getline(cin, bookID);
    auto bookIt = find_if(books.begin(), books.end(),
        [bookID](const Book& book) {
            return book.getBookID() == bookID;
        });
    if (bookIt == books.end()) {
        cout << "Book available to borrow" << endl;
        return;
    }
    else
    {
        if (!bookIt->isAvailable())
        {
            cout << "Book is not available" << endl;
            return;
        }
        cout << "Enter member ID who is borrowing the book:  ";
        cin.ignore();
        getline(cin, memberID);
        auto memberIt = find_if(members.begin(), members.end(),
            [memberID](const Member& member) {
                return member.getMemberID() == memberID;
            });
        if (memberIt == members.end()) {
            cout << "Member not found" << endl;
            return;
        }
        auto borrowIt = find_if(borrows.begin(), borrows.end(),
            [bookID](const Borrow& borrow) {
                return borrow.getBookID() == bookID;
            });
        Borrow borrow(bookIt->getBookID(), memberIt->getMemberID(), borrowIt->getBorrowDate());
        borrows.push_back(borrow);
        memberIt->getMemberID();
        (bookIt->getTitle());
        cout << "Book borrowed successfully" << endl;
    }
}
void returnBook(vector<Member>& members, vector<Borrow>& borrows)
{
    string bookID, memberID;
    cout << "Enter book ID to be return: ";
    cin >> bookID;
    auto borrowIt = find_if(borrows.begin(), borrows.end(),
        [bookID](const Borrow& borrow) {
            return borrow.getBookID() == bookID;
        });
    if (borrowIt == borrows.end()) {
        cout << "No borrow record found for this book" << endl;
        return;
    }
    cout << "Enter the ID of the member who is returning the book:  ";
    cin.ignore();
    getline(cin, memberID);
    auto memberIt = find_if(members.begin(), members.end(),
        [memberID](const Member& member) {
            return member.getMemberID() == memberID;
        });
    if (memberIt == members.end())
    {
        cout << "Member not found" << endl;
        return;
    }
    borrowIt->display();
    memberIt->display();
    cout << "Book returned successfully" << endl;
}

void generateReport(const vector<Book>& books, const vector<Member>& members, const vector<Borrow>& borrows)
{
    // display total number of books, members and borrows
    cout << "Total number of books: " << books.size() << endl;
    cout << "Total number of members: " << members.size() << endl;
    cout << "Total number of borrows: " << borrows.size() << endl;
    // display list of books
    cout << "List of books:" << endl;
    for (const auto& book : books)
    {
        book.display();
    }
    // display list of members
    cout << "List of members:" << endl;
    for (const auto& member : members)
    {
        member.display();
    }
    // display list of borrows
    cout << "List of borrows:" << endl;
    for (const auto& borrow : borrows)
    {
        borrow.display();
    }
}
