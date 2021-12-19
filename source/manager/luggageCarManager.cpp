#include "luggageCarManager.h"

/**
 * @brief reads the information related to luggage cars from a file
 * @param file the file to read the information from
 */
void LuggageCarManager::read(ifstream &file) {
    unsigned numberOfCarriages, numberOfPiles, numberOfSuitcasesPerPile;

    if (file.is_open()) {
        cout << "Successfully opened file! \n";

        while (!file.eof()) {
            file >> numberOfCarriages >> numberOfPiles >> numberOfSuitcasesPerPile;
            LuggageCar luggageCar(numberOfCarriages, numberOfPiles, numberOfSuitcasesPerPile);
            luggageCars.insert(luggageCar);
        }
    } else { cout << "Couldn't open file \n";}
}

/**
 * @brief adds a luggage car
 * @param luggageCar the luggage car to be added
 */
void LuggageCarManager::add(LuggageCar luggageCar) {
    luggageCars.insert(luggageCar);
}

/**
 * @brief removes a luggage car
 * @param luggageCarToRemove the luggage car to be removed
 */
void LuggageCarManager::remove(LuggageCar luggageCarToRemove) {
    luggageCars.erase(luggageCarToRemove);
}

/**
 * @brief writes the changes to a file
 * @param file the file containing the information of the luggage cars
 */
void LuggageCarManager::write(ofstream &file) {
    for (LuggageCar luggageCar: luggageCars) {
        file << luggageCar.getNumberOfCarriages() << " " << luggageCar.getNumberOfPiles() << " " << luggageCar.getNumberOfSuitcasesPerPile();
    }
}

/**
 * @brief shows the luggage cars and their information
 */
void LuggageCarManager::show() {
    for (LuggageCar luggageCar: luggageCars) {
        cout << luggageCar << endl;
    }
}

set<LuggageCar> LuggageCarManager::getLuggageCars() {
    return luggageCars;
}