#include "planeManager.h"

/**
 * @brief reads the information of the planes from a file
 * @param planeFile the file containing the planes' information
 */
void PlaneManager::read(ifstream& planeFile) {
    if (planeFile.is_open()) {
        cout << "Successfully opened plane file!" << endl;
        unsigned capacity, year, month, day, hour, minute, numOfPastServices, numOfScheduledServices, serviceID;
        char sep;
        string type, regis, maintenanceType, responsible;
        Plane key;
        unsigned ID;

        while (planeFile.peek() != EOF) {
            planeFile >> type  >> capacity >> regis >> ID;
            key = Plane(capacity, type, regis, ID);
            planeFile >> numOfPastServices;
            for (unsigned i = 0; i < numOfPastServices; i++) {
                planeFile >> serviceID >> maintenanceType >> day >> sep >> month >> sep >> year >> hour >> sep >> minute >> responsible;
                DateTime serviceSchedule(year, month, day, hour, minute);
                MaintenanceService pastService(serviceID, maintenanceType, serviceSchedule, responsible);
                key.addPastService(pastService);
            }
            planeFile >> numOfScheduledServices;
            for (unsigned i = 0; i < numOfScheduledServices; i++) {
                planeFile >> serviceID >> maintenanceType >> day >> sep >> month >> sep >> year >> hour >> sep >> minute >> responsible;
                DateTime serviceSchedule(year, month, day, hour, minute);
                MaintenanceService scheduledService(serviceID, maintenanceType, serviceSchedule, responsible);
                key.addScheduledService(scheduledService);
            }
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
    for (const Plane &plane: myPlanes) {
        auto pastServices = plane.getPastServices();
        auto scheduledServices = plane.getScheduledServices();

        file << plane.getPlaneType() << " " << plane.getCapacity() << " " << plane.getRegis() << " " << plane.getId() << endl;
        file << plane.getPastServices().size() << endl;
        while(!pastServices.empty()) {
            file << pastServices.front();
            pastServices.pop();
        }
        file << scheduledServices.size() << endl;
        while(!scheduledServices.empty()) {
            file << scheduledServices.front();
            scheduledServices.pop();
        }
    }
}

/**
 * @brief adds a flight
 * @param newFlight flight to add
 * @param filename file to write the changes
 */
int PlaneManager::add(const Plane &newPlane) {
    if (myPlanes.find(Plane(newPlane)) != myPlanes.end())
        return 0;
    myPlanes.insert(newPlane);
    return 1;
}

/**
 * @brief removes a flight
 * @param flightToRemove flight to remove
 * @param filename file to write the changes
 */
int PlaneManager::remove(const Plane &planeToRemove) {
    if (myPlanes.find(planeToRemove) == myPlanes.end())
        return 0;
    else {
        this->myPlanes.erase(myPlanes.find(planeToRemove));
        return 1;
    }
}

/**
 * @brief shows the flights and their information to the users
 */
void PlaneManager::show() {
    for (const Plane &plane: myPlanes) {
        cout << plane <<  endl;
    }
}

/**
 * @return the set of planes
 */
set<Plane>& PlaneManager::get() {
    return myPlanes;
}

/**
 * @param plane instance of Plane
 * @return true if the plane if found, false otherwise
 */
bool PlaneManager::find(Plane plane) {
    return (myPlanes.find(plane) != myPlanes.end());
}

void PlaneManager::setPlanes(set<Plane> updatedPlanes) {
    myPlanes = updatedPlanes;
}