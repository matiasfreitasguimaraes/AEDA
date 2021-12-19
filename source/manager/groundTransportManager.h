#ifndef AEDAPROJECT_GROUNDTRANSPORTMANAGER_H
#define AEDAPROJECT_GROUNDTRANSPORTMANAGER_H
#include <set>
#include "../objects/groundTransport.h"
#include <iostream>
#include <fstream>

class GroundTransportManager{
private:
    set<GroundTransport> myTransport;
public:
    GroundTransportManager();
    void read(ifstream &groundFile);
    int add(GroundTransport newGround);
    int remove(GroundTransport groundToRemove);
    void showSched();
    void write(ostream &file);
    set<GroundTransport> get();
};


#endif //AEDAPROJECT_GROUNDTRANSPORTMANAGER_H
