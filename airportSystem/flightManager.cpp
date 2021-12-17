#include "flightManager.h"

using namespace std;

/**
 * @brief writes the changes made in the flights to the file
 * @param filename the output file
 */
void FlightManager::writeToFile(string &filename) {
    ofstream file(filename, ios_base::trunc);
    for (Flight &flight: flights) {
        file << flight.getFlightId() << " " << flight.getNumberOfFlight() << " " << flight.getDepartureDate() << " " << flight.getArrivalDate() << " " << flight.getOrigin() << " " << flight.getDestination() << endl;
    }
}

/**
 * @brief adds a flight
 * @param newFlight flight to add
 * @param filename file to write the changes
 */
void FlightManager::addFlight(Flight &newFlight, string &filename) {
    flights.push_back(newFlight);
    writeToFile(filename);
}

/**
 * @brief removes a flight
 * @param flightToRemove flight to remove
 * @param filename file to write the changes
 */
void FlightManager::removeFlight(Flight &flightToRemove, string &filename) {
    for (unsigned i = 0; i < flights.size(); i++) {
        if (flights.at(i) == flightToRemove)
            flights.erase(flights.begin() + i);
    }
    writeToFile(filename);
}

/**
 * @brief reads the flights initially in a file
 * @param filename file to read the flights from
 */
void FlightManager::readFlights(string &filename) {
    ifstream flightFile(filename);
    string number, originOfFLight, destinationOfFlight;
    char sep;
    unsigned arrivalYear, arrivalMonth, arrivalDay, arrivalHour, arrivalMinute, flightId;
    unsigned departureYear, departureMonth, departureDay, departureHour, departureMinute;

    while (!flightFile.eof()) {
        flightFile >> flightId >> number >> departureYear >> sep >> departureMonth >> sep >> departureDay >> departureHour >> sep >> departureMinute >> arrivalYear >> sep >>  arrivalMonth >> sep >> arrivalDay >> arrivalHour >> sep >> arrivalMinute >> originOfFLight >> destinationOfFlight;
        DateTime departure(departureYear, departureMonth, departureDay, departureHour, departureMinute);
        DateTime arrival(arrivalYear, arrivalMonth, arrivalDay, arrivalHour, arrivalMinute);
        Flight flight(number, departure, arrival, originOfFLight, destinationOfFlight, flightId);
        cout << flight << endl;
        flights.push_back(flight);
    }
}

/**
 * @brief shows the flights and their information to the users
 */
void FlightManager::showFlights() {
    for (Flight &flight: flights) {
        cout << flight <<  endl;
    }
}