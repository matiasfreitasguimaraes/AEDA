#include "planeManager.h"

/**
 * @brief reads the information of the planes from a file
 * @param planeFile the file containing the planes' information
 */
void PlaneManager::read(ifstream& planeFile) {
    if (planeFile.is_open()) {
        cout << "Successfully opened plane file!" << endl;
        int capacity;
        string type;
        string regis;
        Plane key;
        unsigned ID;
        while (!planeFile.eof()) {
            planeFile >> type  >> capacity >> regis >> ID;
            key = Plane(capacity, type, regis, ID);
            myPlanes.insert(key);
        }
    } else {
        cout << "Couldn't read file input.\n";
    }
}

/**
 * @brief writes the changes made to a file
 * @param file file to save the changes
 */
void PlaneManager::write(ofstream &file) {
    for (Plane plane: myPlanes) {
        file << plane.getPlaneType() << " " << plane.getCapacity() << " "
        << plane.getRegis() << " " << plane.getId() << endl;
    }
}

/**
 * @brief adds a flight
 * @param newFlight flight to add
 * @param filename file to write the changes
 */
void PlaneManager::add(Plane newPlane) {
    myPlanes.insert(newPlane);
}

/**
 * @brief removes a flight
 * @param flightToRemove flight to remove
 * @param filename file to write the changes
 */
void PlaneManager::remove(Plane planeToRemove) {
    this->myPlanes.erase(planeToRemove);
}

/**
 * @brief shows the flights and their information to the users
 */
void PlaneManager::show() {
    for (Plane plane: myPlanes) {
        cout << plane <<  endl;
    }
}

/**
 * @return the set of planes
 */
set<Plane> PlaneManager::get() {
    return myPlanes;
}
