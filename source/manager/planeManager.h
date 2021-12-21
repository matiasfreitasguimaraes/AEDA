#ifndef AEDAPROJECT_PLANEMANAGER_H
#define AEDAPROJECT_PLANEMANAGER_H

#include <set>

#include "../objects/plane.h"

class PlaneManager  {
private:
    set<Plane> myPlanes;
public:
    void read(ifstream& planeFile);
    void write(ofstream &file);
    int add(const Plane &newPlane);
    int remove(const Plane &planeToRemove);
    set<Plane>& get();
    void setPlanes(set<Plane> updatedPlanes);
    bool find(Plane plane);
    void show();
};


#endif //AEDAPROJECT_PLANEMANAGER_H
