#ifndef PROGP5_AIRPORT_H
#define PROGP5_AIRPORT_H

#include <vector>

#include "luggageCar.h"
#include "groundTransport.h"
#include <map>

class Airport {
private:
    vector<LuggageCar> luggageCars;
    std::set<string, GroundTransport> groundTransports;
public:

    void addLuggageCar(LuggageCar &car);
};


#endif //PROGP5_AIRPORT_H
