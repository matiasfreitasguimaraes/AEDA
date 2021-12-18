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
ostream& operator<<(ostream& out, const LuggageCar car) {
    out << "Car's capacity: " << car.getCarTotalCapacity() << endl;
    out << "Car's number of occupied slots: " << car.getNumberOfOccupiedSlots() << endl;
    out << "Car's free slots: " << car.getNumberOfFreeSlots() << endl;
    return out;
}

/**
 * @param car instance of LuggageCar
 * @return the car with lower capacity
 */
bool LuggageCar::operator<(const LuggageCar &car) {
    return this->carCapacity < car.carCapacity;
}

/**
 * TODO: keep track of the amount of luggage a passenger has
 * @brief adds the passengers' luggage to a car
 * @param luggage the passenger's luggage
 */
void LuggageCar::addLuggage(Luggage &luggage) {
    if (trailers.size() < numberOfCarriages) {
        auto trailer = trailers.back();
        if (trailer.size() < numberOfPiles) {
            auto pile = trailer.back();
            if (pile.size() < numberOfSuitcasesPerPile) {
                pile.push(luggage);
            } else {
                trailer.push(stack<Luggage>());
            }
        } else {
            trailers.push(queue<stack<Luggage>>());
        }
    } else {
        cout << "Luggage car is full \n";
    }
}