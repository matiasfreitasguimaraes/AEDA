//
// Created by jpdat on 18/12/21.
//

#ifndef FLIGHTTEST_AIRPORTMANAGER_H
#define FLIGHTTEST_AIRPORTMANAGER_H

#include "../objects/airport.h"

class airportManager {
private:
    set<Airport> airports;
public:
    airportManager();
    void read(ifstream &airportFile);
    void write(ofstream &file);
    int add(Airport newAirport);
    int remove(Airport airportToRemove);
    void listAirports();
    bool findAirport(Airport airport);
    set<Airport>& getAirports();
};


#endif //FLIGHTTEST_AIRPORTMANAGER_H
