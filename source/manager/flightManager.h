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

    ///Writer and reader functions
        ///to files
    void write(ofstream &file);
    void read(ifstream &file);

        ///to console
    void show();

    ///update and delete
    void add(Flight newFlight);
    void remove(Flight flightToRemove);

    ///get atributtes
    set<Flight> get() const;

    ///find element
    Flight find(string numberOfFlight);
};


#endif //AEDAPROJECT_FLIGHTMANAGER_H
