//
// Created by jpdat on 16/12/21.
//

#ifndef AEDAPROJECT_READER_H
#define AEDAPROJECT_READER_H

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <set>
#include <map>
#include "plane.h"
#include "groundTransport.h"

class Reader {
private:

public:
    static set<Plane> readPlanes(ifstream& planeFile);
    static map<string, GroundTransport> readGroundTransport(ifstream groundFile);
};


#endif //AEDAPROJECT_READER_H
