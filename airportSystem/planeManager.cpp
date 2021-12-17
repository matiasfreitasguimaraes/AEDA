//
// Created by Matias Freitas Guimarães on 17/12/2021.
//

#include "planeManager.h"
void PlaneManager::readPlanes(ifstream& planeFile) {
    if (planeFile.is_open()) {
        printf("Susccefully opened input file!\n");
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
        printf("Couldnt read file input.\n");
    }
}