#include "planeManager.h"

/**
 * @brief reads the information of the planes from a file
 * @param planeFile the file containing the planes' information
 */
void PlaneManager::readPlanes(ifstream& planeFile) {
    if (planeFile.is_open()) {
        cout << "Successfully opened input file!\n";
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
        cout << "Couldn't read file input.\n";
    }
}

/**
 * @brief writes the changes made to a file
 * @param file file to save the changes
 */
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
