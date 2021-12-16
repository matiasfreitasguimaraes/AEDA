#ifndef PROGP5_AIRPORT_H
#define PROGP5_AIRPORT_H

#include <vector>
#include <map>

#include "luggageCar.h"
#include "groundTransport.h"

using namespace std;

class Airport {
private:
    vector<LuggageCar> luggageCars;
    map<string, GroundTransport> groundTransports;
public:

    void addLuggageCar(LuggageCar &car);
};


#endif //PROGP5_AIRPORT_H
