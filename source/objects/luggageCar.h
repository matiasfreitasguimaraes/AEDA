#ifndef AEDAPROJECT_LUGGAGECAR_H
#define AEDAPROJECT_LUGGAGECAR_H

#include "luggage.h"

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class LuggageCar {
private:
    const unsigned numberOfCarriages;
    const unsigned numberOfPiles;
    const unsigned numberOfSuitcasesPerPile;
    unsigned carCapacity;
    unsigned numberOfOccupiedSlots;
    queue<queue<stack<Luggage>>> trailers;
public:
    LuggageCar(unsigned carriages, unsigned piles, unsigned suitcasesPerPile);
    unsigned getCarTotalCapacity() const;
    unsigned getNumberOfOccupiedSlots() const;
    unsigned getNumberOfFreeSlots() const;
    bool carIsFull();
    void addLuggage(Luggage &luggage);
    friend ostream& operator<<(ostream& out, const LuggageCar &car);
    bool operator<(const LuggageCar &car);
};

#endif //AEDAPROJECT_LUGGAGECAR_H
