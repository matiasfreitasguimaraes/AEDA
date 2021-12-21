#include "flightManager.h"

/**
 * @brief writes the changes made in the flights to the file
 * @param filename the file to save the changes
 */
 void FlightManager::write(ofstream &file) {

    for (Flight flight: flights) {
        file << flight.getNumberOfFlight() << " "
            << std::setfill('0') << std::setw(2)
            << flight.getDepartureDate().getDay()  << " "
            << std::setfill('0') << std::setw(2)
             << flight.getDepartureDate().getMonth() << " "
             << flight.getDepartureDate().getYear() << " "
             << std::setfill('0') << std::setw(2)
             << flight.getDepartureDate().getHour() << " "
             << std::setfill('0') << std::setw(2)
             << flight.getDepartureDate().getMinute() << " "

             << std::setfill('0') << std::setw(2)
             << flight.getArrivalDate().getDay() << " "
             << std::setfill('0') << std::setw(2)
             << flight.getArrivalDate().getMonth() << " "
             << flight.getArrivalDate().getYear() << " "
             << std::setfill('0') << std::setw(2)
             << flight.getDepartureDate().getHour() << " "
             << std::setfill('0') << std::setw(2)
             << flight.getDepartureDate().getMinute()
             << " " << flight.getOrigin()
             << " " << flight.getDestination()
             << " " << flight.getFlightId() << endl;
    }
}

/**
 * @brief adds a flight
 * @param newFlight flight to be added
 * @return 1 if successfully, 0 otherwise
 */
int FlightManager::add(Flight newFlight) {

    if (this->find(newFlight)) {
        return 0;
    } else {
        flights.insert(newFlight);
        return 1;
    }
}

/**
 * @brief removes a flight
 * @param flightToRemove flight to remove
 */
void FlightManager::remove(Flight flightToRemove) {
    this->flights.erase(flights.find(flightToRemove));
}

/**
 * @brief reads the flights' information from a file
 * @param flightFile the file contaning the flights' information
 */
void FlightManager::read(ifstream &flightFile) {

    if (flightFile.is_open()) {
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
    } else
        printf("Couldn't read file input.\n");
}

/**
 * @brief displays the flights and their information to the users
 */
void FlightManager::show() {

    for (Flight flight: flights) {
        cout << flight <<  endl;
    }
}

/**
 * @return the set of flights
 */
set<Flight>& FlightManager::get() {
    return flights;
}

/**
 * @brief finds a flight by its number
 * @param flight the flight's number
 * @return true if found, false otherwise
 */
bool FlightManager::find(Flight flight) {
    return (flights.find(flight) != flights.end());
}
