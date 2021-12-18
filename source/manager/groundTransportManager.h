#ifndef FLIGHTTEST_GROUNDTRANSPORTMANAGER_H
#define FLIGHTTEST_GROUNDTRANSPORTMANAGER_H
#include <set>
#include "../objects/groundTransport.h"

class GroundTransportManager{
private:
    set<GroundTransport> myTransport;
public:
    void read(ifstream &groundFile);
    void add(GroundTransport newGround);
    void remove(GroundTransport groundToRemove);
    void show() override;
    void write(ostream &file);
};


#endif //FLIGHTTEST_GROUNDTRANSPORTMANAGER_H
