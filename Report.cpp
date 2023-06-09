#include "Report.h"

Report::Report(int a, int b, int r, int u) : availableBooks(a), borrowedBooks(b), returnedBooks(r), unreturnedBooks(u) {}

int Report::getAvailableBooks() const {
    return availableBooks;
}

int Report::getBorrowedBooks() const {
    return borrowedBooks;
}

int Report::getReturnedBooks() const {
    return returnedBooks;
}

int Report::getUnreturnedBooks() const {
    return unreturnedBooks;
}
