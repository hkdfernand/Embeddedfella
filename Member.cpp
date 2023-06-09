#include "member.h"
#include <iostream>

Member::Member(std::string n, std::string c, std::string m) : name(n), contactInformation(c), memberID(m) {}

void Member::setName(std::string n) {
    name = n;
}

void Member::setContactInformation(std::string c) {
    contactInformation = c;
}
void Member::setMemberID(std::string m)
{
    memberID = m;
}

std::string Member::getName() const {
    return name;
}
std::string Member::getMemberID() const
{
    return memberID;
}

std::string Member::getContactInformation() const {
    return contactInformation;
}

void Member::borrowBook(int bookID) {
    borrowingHistory.push_back(bookID);
}

void Member::returnBook(int bookID) {
    for (int i = 0; i < borrowingHistory.size(); i++) {
        if (borrowingHistory[i] == bookID) {
            borrowingHistory.erase(borrowingHistory.begin() + i);
            break;
        }
    }
}

void Member::display() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Contact Information: " << contactInformation << std::endl;
    std::cout << "Borrowing History: ";
    if (borrowingHistory.size() == 0) {
        std::cout << "None" << std::endl;
    }
    else {
        for (int i = 0; i < borrowingHistory.size(); i++) {
            std::cout << borrowingHistory[i];
            if (i < borrowingHistory.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
}

