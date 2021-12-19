#ifndef AEDAPROJECT_PLANEMANAGER_H
#define AEDAPROJECT_PLANEMANAGER_H

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
    void write(ofstream &file);
    set<Plane> get();
};


#endif //AEDAPROJECT_PLANEMANAGER_H
