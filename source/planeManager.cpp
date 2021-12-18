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

void PlaneManager::writeToFile(ostream &file) {

    for (Plane plane: myPlanes) {
        file << plane.getRegis() << " " << plane.getCapacity() << " "
        << plane.getPlaneType() << " " << plane.getId();
    }
}

/**
 * @brief adds a flight
 * @param newFlight flight to add
 * @param filename file to write the changes
 */
void PlaneManager::addFlight(Plane newPlane) {
    myPlanes.insert(newPlane);
}

/**
 * @brief removes a flight
 * @param flightToRemove flight to remove
 * @param filename file to write the changes
 */
void PlaneManager::removeFlight(Plane planeToRemove) {
    this->myPlanes.erase(planeToRemove);
}

/**
 * @brief shows the flights and their information to the users
 */
void PlaneManager::showPlanes() {
    for (Plane plane: myPlanes) {
        cout << plane <<  endl;
    }
}