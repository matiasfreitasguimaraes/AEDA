#include "flight.h"

Flight::Flight(string &number, DateTime &flightDepartureDate, DateTime &flightArrivalDate, string &flightOrigin,
               string &flightDestination, unsigned &Id) : numberOfFlight(number), departureDate(flightDepartureDate),
               arrivalDate(flightArrivalDate), origin(flightOrigin), destination(flightDestination), boughtTickets(0) {
    this->id = Id;
}

Flight::Flight(string &number) {
    this->numberOfFlight = number;
}

/**
 * @return the flight's origin
 */
string Flight::getOrigin() const{
    return origin;
}

/**
 * @return the flight's destination
 */
string Flight::getDestination() const{
    return destination;
}

/**
 * @return the flight's departure date
 */
DateTime Flight::getDepartureDate() const{
    return departureDate;
}

/**
 * @return the flight's arrival date
 */
DateTime Flight::getArrivalDate() const{
    return arrivalDate;
}

/**
 * @return the flight's number
 */
string Flight::getNumberOfFlight() const{
    return numberOfFlight;
}

/**
 * @param out output stream
 * @param flight instance of Flight
 * @return all the flight's information
 */
ostream& operator<<(ostream &out, const Flight &flight) {
    out << "Flight's number: " << flight.getNumberOfFlight() << endl;
    out << "Flight's departure date: " << flight.getDepartureDate() << endl;
    out << "Flight's arrival date: " << flight.getArrivalDate() << endl;
    out << "Flight's origin: "  << flight.getOrigin() << endl;
    out << "Flight's destination: " << flight.getDestination() << endl;
    return out;
}

/**
 * @param nTickets number of tickets bought
 */
void Flight::updateBoughtTickets(int nTickets) {
    boughtTickets += nTickets;
}

/**
 * @return the number of tickets bought
 */
unsigned Flight::getNumberOfTicketsBought() const {
    return boughtTickets;
}

/**
 * @return the flight's ID
 */
unsigned int Flight::getFlightId() const {
    return id;
}

/**
 * @param rhs instance of flight
 * @return the flight with the lower number
 */
bool Flight::operator<(const Flight &rhs) const {
    return numberOfFlight < rhs.getNumberOfFlight();
}

/**
 * @param rhs instance of Flight
 * @return true if two flights have the same number, false otherwise
 */
bool Flight::operator==(const Flight &rhs) const {
    return numberOfFlight == rhs.getNumberOfFlight();
}
