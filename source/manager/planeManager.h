//
// Created by Matias Freitas Guimarães on 17/12/2021.
//

#ifndef FLIGHTTEST_PLANEMANAGER_H
#define FLIGHTTEST_PLANEMANAGER_H
#include <set>
#include "../objects/plane.h"

class PlaneManager  {
private:
    set<Plane> myPlanes;
public:
    void read(ifstream& planeFile);
    void add(Plane newPlane);
    void remove(Plane planeToRemove);
    void show();
    void write(ostream &file);
};


#endif //FLIGHTTEST_PLANEMANAGER_H
