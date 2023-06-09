//
//  Book.h
//  Xcode library management
//
//  Created by Fernand HKD on 2023-04-10.
//  Copyright © 2023 Fernand HKD. All rights reserved.

#include <string>
#include "LibraryItem.h"

class Book : public LibraryItem {
private:
    std::string title;
    std::string author;
    std::string publisher;
    std::string ISBN;
    std::string BookID;
    bool m_isAvailable = true;
public:
    Book();
    Book(std::string t, std::string a, std::string p, std::string i, std::string b);
    void setTitle(std::string t);
    void setAuthor(std::string a);
    void setPublisher(std::string p);
    void setISBN(std::string i);
    void setBookID(std::string b);
    std::string getBookID() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getPublisher() const;
    std::string getISBN() const;
    bool isAvailable() const;
    //void display(const Book& book);
    virtual void display() const override;
    // Overload operator==
    bool operator==(const Book& rhs) const {
        return BookID == rhs.BookID;
    }
};

