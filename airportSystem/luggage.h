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
    bool wantsAutomaticCheckIn();
    unsigned getQuantity() const;
    void setQuantity(unsigned quant);
};

#endif //AEDAPROJECT_LUGGAGE_H
