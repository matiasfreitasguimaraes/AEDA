#include "groundTransportManager.h"

GroundTransportManager::GroundTransportManager() {}

void GroundTransportManager::read(ifstream &groundFile) {
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
        printf("Couldn't read input file.\n");
    }
}

int GroundTransportManager::add(GroundTransport newGround) {
    if (myTransport.find(newGround) != myTransport.end())
        return 0;
    myTransport.insert(newGround);
    return 1;
}

int GroundTransportManager::remove(GroundTransport groundToRemove) {
    if (myTransport.find(groundToRemove) == myTransport.end())
        return 0;
    myTransport.erase(myTransport.find(groundToRemove));
    return 1;
}

void GroundTransportManager::showSched() {

}

set<GroundTransport> GroundTransportManager::getMyTransport() {
    return myTransport;
}
