#include "luggage.h"

Luggage::Luggage(Passenger ownerOfLuggage, bool option, unsigned quant) : owner(ownerOfLuggage){
    this->automaticCheckIn = option;
    this->quantity = quant;
}

/**
 * @return the amount of luggage that belongs to a passenger
 */
unsigned int Luggage::getQuantity() const {
    return quantity;
}
