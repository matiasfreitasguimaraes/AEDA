#include "airport.h"

Airport::Airport(string airportName) : name(airportName) {}

string Airport::getName() {
    return this->name;
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

