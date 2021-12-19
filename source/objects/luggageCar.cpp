#include "luggageCar.h"

LuggageCar::LuggageCar(unsigned int carriages, unsigned int piles, unsigned int suitcases)
    : numberOfCarriages(carriages), numberOfPiles(piles), numberOfSuitcasesPerPile(suitcases) {
    numberOfOccupiedSlots = 0;
    carCapacity = numberOfCarriages * numberOfPiles * numberOfSuitcasesPerPile;
}

/**
 * @return the car's total capacity
 */
unsigned int LuggageCar::getCarTotalCapacity() const {
    return carCapacity;
}

/**
 * @return the number of occupied slots in the car
 */
unsigned int LuggageCar::getNumberOfOccupiedSlots() const {
    return numberOfOccupiedSlots;
}

/**
 * @return the number of free slots in the car
 */
unsigned int LuggageCar::getNumberOfFreeSlots() const {
    return carCapacity - numberOfOccupiedSlots;
}

/**
 * @return true if the car is full, false otherwise
 */
bool LuggageCar::carIsFull() {
    return numberOfOccupiedSlots == carCapacity;
}

/**
 * @param out output stream
 * @param car instance of LuggageCar
 * @return all the car information
 */
ostream& operator<<(ostream& out, const LuggageCar &car) {
    out << "Car's capacity: " << car.getCarTotalCapacity() << endl;
    out << "Car's number of occupied slots: " << car.getNumberOfOccupiedSlots() << endl;
    out << "Car's free slots: " << car.getNumberOfFreeSlots() << endl;
    return out;
}

/**
 * @param car instance of LuggageCar
 * @return the car with lower capacity
 */
bool LuggageCar::operator<(const LuggageCar &car) const {
    return this->carCapacity < car.carCapacity;
}

/**
 * @brief adds the passenger's luggage to a car
 * @param luggage the passenger's luggage
 */
void LuggageCar::addLuggage(Luggage &luggage) {
    for (unsigned i = 0; i < luggage.getQuantity(); i++) {
        if (trailers.empty()) {
            stack<int> tempStack;
            tempStack.push(1);
            queue<stack<int>> tempQueue;
            tempQueue.push(tempStack);
        } else {
            if (trailers.size() < numberOfCarriages) {
                if (trailers.back().size() < numberOfPiles) {
                    if (trailers.back().back().size() < numberOfSuitcasesPerPile)
                        trailers.back().back().push(1);
                    else {
                        stack<int> auxStack;
                        auxStack.push(1);
                        trailers.back().push(auxStack);
                    }
                } else {
                    queue<stack<int>> auxQueue;
                    stack<int> auxStack;
                    auxStack.push(1);
                    auxQueue.push(auxStack);
                    trailers.push(auxQueue);
                }
            }
        }
    }
    numberOfOccupiedSlots += luggage.getQuantity();
}

/**
 * @return the number of carriages of a luggage car
 */
unsigned int LuggageCar::getNumberOfCarriages() const {
    return numberOfCarriages;
}

/**
 * @return the number of piles of a luggage car
 */
unsigned int LuggageCar::getNumberOfPiles() const {
    return numberOfPiles;
}

/**
 * @return the number of suitcases per pile of a luggage car
 */
unsigned int LuggageCar::getNumberOfSuitcasesPerPile() const {
    return numberOfSuitcasesPerPile;
}