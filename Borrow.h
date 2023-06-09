//
//  borrow.h
//  Xcode library management
//
//  Created by Fernand HKD on 2023-04-10.
//  Copyright © 2023 Fernand HKD. All rights reserved.
//

#ifndef borrow_h
#define borrow_h
#pragma once
#include <ctime>
#include "LibraryItem.h"
#include <string>

class Borrow {
private:
    std::string bookID;
    std::string memberID;
    time_t borrowDate;

public:
    Borrow(std::string bID, std::string mID, time_t bDate);
    std::string getBookID() const;
    std::string getMemberID() const;
    time_t getBorrowDate() const;
    void display() const;
};
#endif /* borrow_h */
