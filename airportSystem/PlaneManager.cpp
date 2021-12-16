//
// Created by jpdat on 16/12/21.
//

#include "PlaneManager.h"

PlaneManager::PlaneManager() {}

void PlaneManager::readPlanes() {
    ifstream planeFile;
    planeFile.open("savedPlanes.txt");
    if (planeFile.is_open()) {
        printf("Succesfully opened savedPlanes text file!\n");
        string capacity;
        string type;
        string regis;
        while (!planeFile.eof()) {
            getline(planeFile, regis);
            getline(planeFile, type);
            getline(planeFile, capacity);
            Plane(stoul(capacity), type, regis);
        }
    } else {
        printf("Couldnt open savedPlanes text file. Back to plane manager.\n");
    }
}

int PlaneManager::addPlane() {
    string type; string regis; string capacity;
    printf("Please enter the plane type.\n");
    do {
        cin >> type;
        if ()
        if (cin.bad() || cin.fail()) {
            printf("%s", errorMessage);
        }
    } while (cin.bad() || cin.fail())

}