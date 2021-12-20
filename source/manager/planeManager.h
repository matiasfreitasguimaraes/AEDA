#ifndef AEDAPROJECT_PLANEMANAGER_H
#define AEDAPROJECT_PLANEMANAGER_H

#include <set>

#include "../objects/plane.h"

class PlaneManager  {
private:
    set<Plane> myPlanes;
public:
    ///Writer and reader functions
        ///to files
    void read(ifstream& planeFile);
    void write(ofstream &file);
        ///to console
    void show();

    ///update and delete
    int add(Plane newPlane);
    int remove(Plane planeToRemove);

    ///get atributtes
    set<Plane> get();
};


#endif //AEDAPROJECT_PLANEMANAGER_H
