//Book.cpp
#include "Book.h"
#include <iostream>

Book::Book(std::string t, std::string a, std::string p, std::string i, std::string b) {
    title = t;
    author = a;
    publisher = p;
    ISBN = i;
    BookID = b;

}

void Book::setTitle(std::string t) {
    title = t;
}

void Book::setAuthor(std::string a) {
    author = a;
}

void Book::setPublisher(std::string p) {
    publisher = p;
}

void Book::setISBN(std::string i)
{
    ISBN = i;
}
void Book::setBookID(std::string b)
{
    BookID = b;
}
std::string Book::getBookID() const
{
    return BookID;
}
std::string Book::getTitle() const
{
    return title;
}

std::string Book::getAuthor() const
{
    return author;
}

std::string Book::getPublisher() const {
    return publisher;
}

std::string Book::getISBN() const {
    return ISBN;
}
bool operator==(const Book& lhs, const Book& rhs)
{
    return lhs.getBookID() == rhs.getBookID();
}
bool Book::isAvailable() const
{
    return m_isAvailable;
}

void Book::display() const
{
    std::cout << "Title: " << getTitle() << std::endl;
    std::cout << "Author: " << getAuthor() << std::endl;
    std::cout << "Publisher: " << getPublisher() << std::endl;
    std::cout << "ISBN: " << getISBN() << std::endl;
    std::cout << "Book ID: " << getBookID() << std::endl;
    std::cout << std::endl;
}

/*void display(const Book& book)
{
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Publisher: " << publisher << std::endl;
    std::cout << "ISBN: " << ISBN << std::endl;
}*/

