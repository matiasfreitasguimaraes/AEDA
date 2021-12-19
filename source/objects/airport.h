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
    vector<LuggageCar> luggageCars;
public:
    Airport(string airportName);
    void addGT(GroundTransport GT);
    int removeGT(GroundTransport GT);
    bool findGT(string GTName);
    void showGTs();
    GroundTransport getGT(string name);
    string getName();
    set<GroundTransport> getGT();
    bool operator<(const Airport &rhs) const;
    bool operator==(const Airport &rhs) const;
};


#endif //AEDAPROJECT_AIRPORT_H
