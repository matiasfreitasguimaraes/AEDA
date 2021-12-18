#ifndef PROGP5_AIRPORT_H
#define PROGP5_AIRPORT_H

#include <vector>

#include "luggageCar.h"
#include "groundTransport.h"
#include <map>
#include "../manager/groundTransportManager.h"

class Airport {
private:
    const string name;
    set<LuggageCar> luggageCars;
    set<GroundTransport> closeTransports;
public:
    Airport(string itsName);
    void addLuggageCar(LuggageCar lugCar);
    int addTransport(GroundTransport newGT);
    int removeTransport(GroundTransport GTToRemove);
    void showTransports();
};


#endif //PROGP5_AIRPORT_H
