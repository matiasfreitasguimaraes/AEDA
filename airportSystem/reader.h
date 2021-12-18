#ifndef AEDAPROJECT_READER_H
#define AEDAPROJECT_READER_H

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <set>

#include "plane.h"
#include "groundTransport.h"
#include "dateTime.h"
#include "flight.h"

class Reader {
private:

public:
    static set<Plane> readPlanes(ifstream& planeFile);
    static set<GroundTransport> readGroundTransport(ifstream &groundFile);
    static set<Flight> readFlight(ifstream &flightFile);
};


#endif //AEDAPROJECT_READER_H
