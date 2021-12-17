#ifndef READERTEST_FLIGHTMANAGER_H
#define READERTEST_FLIGHTMANAGER_H

#include <vector>
#include <fstream>

#include "flight.h"

using namespace std;

class FlightManager {
private:
    vector<Flight> flights;
    void writeToFile(string &filename);
public:
    void addFlight(Flight &newFlight, string &filename);
    void removeFlight(Flight &flightToRemove, string &filename);
    void readFlights(string &filename);
    void showFlights();
};


#endif //READERTEST_FLIGHTMANAGER_H
