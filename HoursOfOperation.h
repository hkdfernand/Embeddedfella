#pragma once
#include <string>
#include "LibraryItem.h" 

class HoursOfOperation {
private:
    std::string daysOpen;
    std::string hoursOpen;

public:
    HoursOfOperation();
    HoursOfOperation(std::string d, std::string h);
    std::string getDaysOpen() const;
    std::string getHoursOpen() const;
};

