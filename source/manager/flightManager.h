#ifndef AEDAPROJECT_FLIGHTMANAGER_H
#define AEDAPROJECT_FLIGHTMANAGER_H

#include <vector>
#include <fstream>
#include <set>

#include "../objects/flight.h"

using namespace std;

class FlightManager{
private:
    set<Flight> flights;
public:
    void write(ostream &file);
    void add(Flight newFlight);
    void remove(Flight flightToRemove);
    void read(ifstream &file);
    void show();
};


#endif //AEDAPROJECT_FLIGHTMANAGER_H
