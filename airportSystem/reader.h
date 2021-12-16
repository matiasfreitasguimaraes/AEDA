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
    static set<Plane> readPlanes(string &filename);
    static map<string, GroundTransport> readGroundTransport(string &filename);
};


#endif //AEDAPROJECT_READER_H
