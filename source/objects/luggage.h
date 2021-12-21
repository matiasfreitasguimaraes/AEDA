#ifndef AEDAPROJECT_LUGGAGE_H
#define AEDAPROJECT_LUGGAGE_H

#include "passenger.h"

class Luggage {
private:
    Passenger owner;
    bool automaticCheckIn;
    unsigned quantity;
public:
    Luggage(Passenger ownerOfLuggage, bool option, unsigned quant);
    unsigned getQuantity() const;
};

#endif //AEDAPROJECT_LUGGAGE_H