//
// Created by jpdat on 16/12/21.
//

#ifndef AEDAPROJECT_PLANEMANAGER_H
#define AEDAPROJECT_PLANEMANAGER_H

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include "plane.h"

class PlaneManager {
private:
    vector<Plane> menuPlanes;
    vector<Plane> loadedPlanes;
    const char* errorMessage = "Ops, something went bad. Care to try again?";
    const string planeManager = "You are now in the Plane manager menu\n"
                                "1 - Load planes\n"
                                "2 - Save slanes\n"
                                "3 - Add new plane\n"
                                "4 - Remove plane\n"
                                "5 - Edit plane\n"
                                "0 - Go back\n";
public:
    PlaneManager();
    void readPlanes();
    void writePlanes();
    int addPlane();
    void removePlane();
};


#endif //AEDAPROJECT_PLANEMANAGER_H
