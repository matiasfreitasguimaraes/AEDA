#ifndef PROGP5_AIRPORT_H
#define PROGP5_AIRPORT_H

#include <vector>

#include "luggageCar.h"
#include "groundTransport.h"
#include <map>

class Airport {
private:
    const string name;
    std::set<GroundTransport> groundTransportBST;
    // vector<LuggageCar> luggageCars;
public:
    Airport(string airportName);
    void addGT(GroundTransport GT);
    int removeGT(GroundTransport GT);
    bool findGT(string GTName);
    void showGTs();
    GroundTransport getGT(string name);
    string getName();
    bool operator<(const Airport &rhs) const;
    bool operator==(const Airport &rhs) const;
    // void addLuggageCar(LuggageCar &car);
};


#endif //PROGP5_AIRPORT_H
