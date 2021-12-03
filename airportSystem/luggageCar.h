#ifndef AEDAPROJECT_LUGGAGECAR_H
#define AEDAPROJECT_LUGGAGECAR_H

#include <iostream>

using namespace std;

class LuggageCar {
private:
    const unsigned numberOfCarriages;
    const unsigned numberOfPiles;
    const unsigned numberOfsuitcasesPerPile;
    unsigned carCapacity;
    unsigned numberOfOccupiedSlots;
public:
    LuggageCar(unsigned carriages, unsigned piles, unsigned suitcasesPerPile);
    unsigned getCarTotalCapacity() const;
    unsigned getNumberOfOccupiedSlots() const;
    unsigned getNumberOfFreeSlots() const;
    bool carIsFull();
    friend ostream& operator<<(ostream& out, const LuggageCar &car);
};




#endif //AEDAPROJECT_LUGGAGECAR_H
