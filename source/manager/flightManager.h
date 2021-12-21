#ifndef AEDAPROJECT_FLIGHTMANAGER_H
#define AEDAPROJECT_FLIGHTMANAGER_H

#include <fstream>
#include <set>

#include "../objects/flight.h"

using namespace std;

class FlightManager{
private:
    set<Flight> flights;
public:
    void write(ofstream &file);
    void read(ifstream &file);
    void show();
    int add(Flight newFlight);
    void remove(Flight flightToRemove);
    set<Flight>& get();
    bool find(Flight flight);
};


#endif //AEDAPROJECT_FLIGHTMANAGER_H
