#include "airport.h"

Airport::Airport() : groundTransports(GroundTransport()) {}

void Airport::addLuggageCar(LuggageCar &car) {
    luggageCars.push_back(car);
}
