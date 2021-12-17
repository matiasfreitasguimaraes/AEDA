#include "flight.h"

using namespace std;

/**
 * @param numberOfFlight the flight's number
 * @param departureDate the flight's departure date
 * @param arrivalDate the flight's arrival date
 * @param origin the flight's origin
 * @param destination the flight's destination
 */
Flight::Flight(string &number, DateTime &flightDepartureDate, DateTime &flightArrivalDate, string &flightOrigin,
               string &flightDestination, unsigned &Id) : numberOfFlight(number), departureDate(flightDepartureDate),
               arrivalDate(flightArrivalDate), origin(flightOrigin), destination(flightDestination), boughtTickets(0) {
    this->id = Id;
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
 * @param destination the flight's new destination
 */
void Flight::setDestination(string flightDestination) {
    this->destination = flightDestination;
}

/**
 * @param out output stream
 * @param flight instance of Flight
 * @return all the flight information
 */
ostream& operator<<(ostream &out, const Flight &flight) {
    out << "Flight's ID: " << flight.getFlightId() << endl;
    out << "Flight number: " << flight.getNumberOfFlight() << endl;
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

bool Flight::operator==(const Flight &flight) {
    return (numberOfFlight == flight.getNumberOfFlight()
        && departureDate == flight.getDepartureDate()
        && arrivalDate == flight.getArrivalDate()
        && origin == flight.getOrigin()
        && destination == flight.getDestination()
    );
}

unsigned int Flight::getFlightId() const {
    return id;
}

/**
 * @return true if a ticket for a flight can be bought, false otherwise
 */
