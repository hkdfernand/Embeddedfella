#pragma once
#include <string>
#include <vector>
#include "LibraryItem.h"

class Member : public LibraryItem {
private:
    std::string name;
    std::string contactInformation;
    std::string memberID;
    std::vector<int> borrowingHistory;

public:
    Member();
    Member(std::string n, std::string c,std::string m);
    void setName(std::string n);
    void setContactInformation(std::string c);
    void setMemberID(std::string m);
    std::string getMemberID() const;
    std::string getName() const;
    std::string getContactInformation() const;
    void borrowBook(int bookID);
    void returnBook(int bookID);
    void display() const override;
};
