#ifndef AEDAPROJECT_AIRPORTMANAGER_H
#define AEDAPROJECT_AIRPORTMANAGER_H

#include "../objects/airport.h"

class airportManager {
private:
    set<Airport> airports;
public:
    ///Constructor
    airportManager();

    ///Writer and reader functions
    void read(ifstream &file);
    void write(ofstream &file);

    ///update and delete
    int add(Airport newAirport);
    int remove(Airport airportToRemove);

    ///get atributtes
    set<Airport>& get();

    ///find element
    bool find(Airport airport);
    void show();
};


#endif //AEDAPROJECT_AIRPORTMANAGER_H
