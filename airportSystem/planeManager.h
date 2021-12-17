//
// Created by Matias Freitas Guimarães on 17/12/2021.
//

#ifndef FLIGHTTEST_PLANEMANAGER_H
#define FLIGHTTEST_PLANEMANAGER_H
#include <set>
#include "plane.h"

class PlaneManager {
private:
    set<Plane> myPlanes;
public:
    void readPlanes(ifstream& planeFile)
};


#endif //FLIGHTTEST_PLANEMANAGER_H
