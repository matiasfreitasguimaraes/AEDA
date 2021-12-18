#include "flightManager.h"

using namespace std;

/**
 * @brief writes the changes made in the flights to the file
 * @param filename the output file
 */
 void FlightManager::write(ostream &file) {
    for (Flight flight: flights) {
        file << flight.getFlightId() << " " << flight.getNumberOfFlight() << " "
             << flight.getDepartureDate() << " " << flight.getArrivalDate()
             << " " << flight.getOrigin() << " " << flight.getDestination() << endl;
    }
}

/**
 * @brief adds a flight
 * @param newFlight flight to add
 * @param filename file to write the changes
 */
void FlightManager::add(Flight newFlight) {
    flights.insert(newFlight);
}

/**
 * @brief removes a flight
 * @param flightToRemove flight to remove
 * @param filename file to write the changes
 */
void FlightManager::remove(Flight flightToRemove) {
    this->flights.erase(flightToRemove);
}

/**
 * @brief reads the flights initially in a file
 * @param ostream to how the value
 */
void FlightManager::read(ifstream &flightFile) {
    if (flightFile.is_open()) {
        printf("Susccefully opened input file!\n");
        string number;
        DateTime arrive , departure;
        unsigned int hour, min, year, month, day, id;
        string destiny, origin;
        while (flightFile.peek() != EOF) {
            flightFile >> number;
            flightFile >> day >> month >>  year >> hour >> min;
            arrive = DateTime(year, month, day, hour, min);
            flightFile >> day >> month >>  year >> hour >> min;
            departure = DateTime(year, month, day, hour, min);
            flightFile >> origin >> destiny >> id;
            add(Flight(number, arrive, departure, origin, destiny, id));
        }
    } else {
        printf("Couldnt read file input.\n");
    }
}

/**
 * @brief shows the flights and their information to the users
 */
void FlightManager::show() {
    for (Flight flight: flights) {
        cout << flight <<  endl;
    }
}
