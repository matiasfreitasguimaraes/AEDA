//
// Created by Matias Freitas Guimarães on 18/12/2021.
//

#ifndef FLIGHTTEST_AIRPORTMANANGER_H
#define FLIGHTTEST_AIRPORTMANANGER_H

#include "../objects/airport.h"
#include <iostream>
#include <fstream>


class airportManager {
private:
    set<Airport> airports;
public:
    airportManager();
    void read(ifstream &airportFile);
    void write(ostream &file);
    int add(Airport newAirport);
    int remove(Airport airportToRemove);
};


#endif //FLIGHTTEST_AIRPORTMANANGER_H
