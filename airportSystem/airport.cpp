#include "airport.h"

Airport::Airport() {}

void Airport::addLuggageCar(LuggageCar &car) {
    luggageCars.push_back(car);
}
