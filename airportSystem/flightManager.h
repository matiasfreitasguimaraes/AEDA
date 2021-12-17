#ifndef READERTEST_FLIGHTMANAGER_H
#define READERTEST_FLIGHTMANAGER_H

#include <vector>
#include <fstream>
#include <set>

#include "flight.h"

using namespace std;

class FlightManager {
private:
    set<Flight> flights;

public:
    void writeToFile(ostream &file);
    void addFlight(Flight newFlight);
    void removeFlight(Flight flightToRemove);
    void readFlights(ifstream &file);
    void showFlights();
};


#endif //READERTEST_FLIGHTMANAGER_H
