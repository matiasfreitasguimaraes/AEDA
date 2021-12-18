#include "reader.h"

set<Plane> Reader::readPlanes(ifstream& planeFile) {
    set<Plane> myPlanes;
    if (planeFile.is_open()) {
        printf("Successfully opened input file!\n");
        int capacity;
        string type;
        string regis;
        Plane key;
        unsigned ID;
        while (!planeFile.eof()) {
            planeFile >> regis >> capacity >> type >> ID;
            key = Plane(capacity, type, regis, ID);
            if (myPlanes.find(key) != myPlanes.end()){
                cout << "Plane with " << key.getRegis() << " already exist" << endl;
            }
            else{
                myPlanes.insert(key);
            }
        }
    } else {
        printf("Couldn't read file input.\n");
    }
    return myPlanes;
}




