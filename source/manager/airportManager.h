#ifndef AEDAPROJECT_AIRPORTMANAGER_H
#define AEDAPROJECT_AIRPORTMANAGER_H

#include <fstream>

#include "../objects/airport.h"

class AirportManager {
private:
    set<Airport> airports;
public:
    void read(ifstream &file);
    void write(ofstream &file);
    int add(Airport newAirport);
    int remove(Airport airportToRemove);
    set<Airport>& get();
    bool find(Airport airport);
    void show();
};


#endif //AEDAPROJECT_AIRPORTMANAGER_H
