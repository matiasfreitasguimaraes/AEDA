#include "groundTransportManager.h"

void GroundTransportManager::readGroundTransport(ifstream &groundFile) {
    if (groundFile.is_open()) {
        printf("Susccefully opened input file!\n");
        string type;
        double airDis;
        set<DateTime> sched;
        unsigned int hour, min, i;
        while (!groundFile.eof()) {
            groundFile >> type >> airDis >> i;
            for (unsigned int j = 0; j < i; ++j) {
                groundFile >> hour >> min;
                sched.insert(DateTime(hour,min));
                myTransport.insert(GroundTransport(type, sched, airDis));
            }
            sched.clear();
        }
    } else {
        printf("Couldnt read file input.\n");
    }
    return myTransport;
}
