#ifndef AEDAPROJECT_FLIGHTMANAGER_H
#define AEDAPROJECT_FLIGHTMANAGER_H

#include <fstream>
#include <set>

#include "../objects/flight.h"

class FlightManager{
private:
    set<Flight> flights;
public:
    void read(ifstream &file);
    void write(ofstream &file);
    int add(Flight newFlight);
    void remove(Flight flightToRemove);
    set<Flight>& get();
    bool find(Flight flight);
    void show();
};


#endif //AEDAPROJECT_FLIGHTMANAGER_H
