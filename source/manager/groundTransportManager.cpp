#include "groundTransportManager.h"

/**
 * @brief reads the information related to the ground transports close to an airport
 * @param groundFile file containing the information related to the ground transports
 */
void GroundTransportManager::read(ifstream &groundFile) {
    if (groundFile.is_open()) {
        printf("Successfully opened input file!\n");
        string type;
        double airDis;
        set<DateTime> sched;
        unsigned hour, min, numberOfTransportSchedules;
        while (!groundFile.eof()) {
            groundFile >> type >> airDis >> numberOfTransportSchedules;
            for (unsigned int j = 0; j < numberOfTransportSchedules; ++j) {
                groundFile >> hour >> min;
                sched.insert(DateTime(hour,min));
                myTransport.insert(GroundTransport(type, sched, airDis));
            }
            sched.clear();
        }
    } else {
        printf("Couldn't read file input.\n");
    }
}
