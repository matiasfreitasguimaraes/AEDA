#ifndef AEDAPROJECT_AIRPORTMANAGER_H
#define AEDAPROJECT_AIRPORTMANAGER_H

#include "../objects/airport.h"

class airportManager {
private:
    set<Airport> airports;
public:
    airportManager();
    void read(ifstream &file);
    void write(ofstream &file);
    int add(Airport newAirport);
    int remove(Airport airportToRemove);
    void list();
    bool find(Airport airport);
    set<Airport>& get();
};


#endif //AEDAPROJECT_AIRPORTMANAGER_H
