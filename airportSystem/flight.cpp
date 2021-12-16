#include "flight.h"
#include "ticket.h"

using namespace std;

/**
 * @param numberOfFlight the flight's number
 * @param departureDate the flight's departure date
 * @param arrivalDate the flight's arrival date
 * @param origin the flight's origin
 * @param destination the flight's destination
 */
Flight::Flight(string &number, Date &flightDepartureDate, Date &flightArrivalDate, string &flightOrigin,
               string &flightDestination, Plane &plane) : departureDate(flightDepartureDate), arrivalDate(flightArrivalDate) {
    this->numberOfFlight = number;
    this->origin = flightOrigin;
    this->destination = flightDestination;
    this->boughtTickets = 0;
    this->assignedPlane = plane;
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
Date Flight::getDepartureDate() const{
    return departureDate;
}

/**
 * @return the flight's arrival date
 */
Date Flight::getArrivalDate() const{
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

/**
 * @return true if a ticket for a flight can be bought, false otherwise
 */
bool Flight::canBuyTicket() {
    return boughtTickets < assignedPlane.getCapacity();
}

void Flight::buyTicket(Passenger &passenger) {
    if (canBuyTicket()) {
        tickets.push_back(Ticket(*this, passenger));
        boughtTickets++;
    }
}