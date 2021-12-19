#include "groundTransportManager.h"

GroundTransportManager::GroundTransportManager() {}

/**
 * @brief reads the ground transports' information from a file
 * @param groundFile the file containing the information related to the ground transports
 */
void GroundTransportManager::read(ifstream &groundFile) {
    if (groundFile.is_open()) {
        printf("Successfully opened input file!\n");
        string type;
        unsigned int airDis;
        set<DateTime> sched;
        unsigned int hour, min, i;
        while (!groundFile.eof()) {
            groundFile >> type >> airDis >> i;
            for (unsigned int j = 0; j < i; ++j) {
                groundFile >> hour >> min;
                sched.insert(DateTime(hour,min));
                myTransport.insert(GroundTransport(type, type, airDis));
            }
            sched.clear();
        }
    } else {
        printf("Couldn't read input file.\n");
    }
}

/**
 * @brief adds a new ground transport if it not exists already
 * @param newGround the ground transport to be added
 * @return 1 if successfully, false otherwise
 */
int GroundTransportManager::add(GroundTransport newGround) {
    if (myTransport.find(newGround) != myTransport.end())
        return 0;
    myTransport.insert(newGround);
    return 1;
}

/**
 * @brief removes an existing ground transport
 * @param groundToRemove ground transport to be removed
 * @return 1 if successfully, 0 otherwise
 */
int GroundTransportManager::remove(GroundTransport groundToRemove) {
    if (myTransport.find(groundToRemove) == myTransport.end())
        return 0;
    myTransport.erase(myTransport.find(groundToRemove));
    return 1;
}

/**
 * @brief shows schedule for the ground transports
 */
void GroundTransportManager::showSched() {
    for (GroundTransport groundTransport: myTransport) {
        groundTransport.showSched();
    }
}

/**
 * @return the set of ground transports
 */
set<GroundTransport> GroundTransportManager::getMyTransport() {
    return myTransport;
}
