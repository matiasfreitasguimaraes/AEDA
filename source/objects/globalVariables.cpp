#include "globalVariables.h"

DateTime GlobalVariables::getCurrentDate() {
    return this->currentDate;
}

void GlobalVariables::setCurrentDate(DateTime today) {
    this->currentDate = today;
}