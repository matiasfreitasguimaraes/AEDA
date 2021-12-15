#ifndef PROGP5_AIRPORT_H
#define PROGP5_AIRPORT_H

#include <vector>

#include "luggageCar.h"
#include "groundTransport.h"
#include "bst.h"

class Airport {
private:
    vector<LuggageCar> luggageCars;
    BST<GroundTransport> groundTransports;
public:
    Airport();

};


#endif //PROGP5_AIRPORT_H
