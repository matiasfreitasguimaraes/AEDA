#include "luggage.h"

Luggage::Luggage(Passenger ownerOfLuggage, bool option, unsigned quant) : owner(ownerOfLuggage){
    this->automaticCheckIn = option;
    this->quantity = quant;
}

/**
 * @return true if the passenger wants automatic check in, false otherwise
 */
bool Luggage::wantsAutomaticCheckIn() {
    return automaticCheckIn;
}

/**
 * @return the amount of luggage that belongs to a passenger
 */
unsigned int Luggage::getQuantity() const {
    return quantity;
}

/**
 * @param quant the new quantity of luggage
 */
void Luggage::setQuantity(unsigned int quant) {
    this->quantity = quant;
}
