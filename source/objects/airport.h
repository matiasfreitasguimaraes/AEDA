#ifndef PROGP5_AIRPORT_H
#define PROGP5_AIRPORT_H

#include <vector>

#include "luggageCar.h"
#include "groundTransport.h"
#include <map>

class Airport {
private:
    string name;
    std::set<GroundTransport> groundTransportBST;
    // vector<LuggageCar> luggageCars;
public:
    Airport(string name);
    int addGT(GroundTransport GT);
    int removeGT(GroundTransport GT);
    int editGT(GroundTransport GT);
    void showGTs();
    // void addLuggageCar(LuggageCar &car);
};


#endif //PROGP5_AIRPORT_H
