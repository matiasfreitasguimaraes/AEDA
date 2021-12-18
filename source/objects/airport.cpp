#include "airport.h"

Airport::Airport(string airportName) {
    this->name = airportName;
}

bool Airport::operator<(const Airport &rhs) const {
    return this->name < rhs.name;
}

bool Airport::operator==(const Airport &rhs) const {
    return this->name == rhs.name;
}

/*void Airport::addLuggageCar(LuggageCar &car) {
    luggageCars.push_back(car);
}*/

