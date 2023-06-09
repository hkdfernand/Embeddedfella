#include "HoursOfOperation.h"

HoursOfOperation::HoursOfOperation(std::string d, std::string h) : daysOpen(d), hoursOpen(h) {}

std::string HoursOfOperation::getDaysOpen() const {
    return daysOpen;
}

std::string HoursOfOperation::getHoursOpen() const {
    return hoursOpen;
}
