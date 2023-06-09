//
//  borrow.cpp
//  Xcode library management
//
//  Created by Fernand HKD on 2023-04-10.
//  Copyright © 2023 Fernand HKD. All rights reserved.
//

#include <stdio.h>
#include "borrow.h"
#include <iostream>
using namespace std;
Borrow::Borrow(std::string bID, std::string mID, time_t bDate) : bookID(bID), memberID(mID), borrowDate(bDate) {}

std::string Borrow::getBookID() const {
    return bookID;
}

std::string Borrow::getMemberID() const {
    return memberID;
}

time_t Borrow::getBorrowDate() const {
    return borrowDate;
}
void Borrow::display() const
{
    std::cout << "bookID: " << getBookID() << std::endl;
    std::cout << "memberID: " << getMemberID() << std::endl;
    std::cout << "borrowDate: " << getBorrowDate() << std::endl;
    std::cout << std::endl;
}


