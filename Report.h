#pragma once
#include "LibraryItem.h"
class Report {
private:
    int availableBooks;
    int borrowedBooks;
    int returnedBooks;
    int unreturnedBooks;

public:
    Report(int a, int b, int r, int u);
    int getAvailableBooks() const;
    int getBorrowedBooks() const;
    int getReturnedBooks() const;
    int getUnreturnedBooks() const;
};

