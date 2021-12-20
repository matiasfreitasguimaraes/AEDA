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
    int add(const Plane &newPlane);
    int remove(const Plane &planeToRemove);

    ///get atributtes
    set<Plane> get();

    bool find(Plane plane);
};


#endif //AEDAPROJECT_PLANEMANAGER_H
