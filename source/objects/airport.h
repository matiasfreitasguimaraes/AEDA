#ifndef AEDAPROJECT_AIRPORT_H
#define AEDAPROJECT_AIRPORT_H

#include <vector>
#include <set>

#include "luggageCar.h"
#include "groundTransport.h"


class Airport {
private:
    const string name;
    set<GroundTransport> groundTransport;
    vector<LuggageCar> luggageCars; // TODO: assign GT's to respective airports
public:
    Airport(string airportName);
    void addGT(GroundTransport GT);
    void removeGT(GroundTransport GT);
    bool findGT(string GTName);
    void showGTs();
    GroundTransport getGT(string name);
    string getName();
    set<GroundTransport>& get();
    bool operator<(const Airport &rhs) const;
    bool operator==(const Airport &rhs) const;
};


#endif //AEDAPROJECT_AIRPORT_H
