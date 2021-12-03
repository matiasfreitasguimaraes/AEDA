#include "flight.h"

using namespace std;

/**
 * @param numberOfFlight the flight's number
 * @param departureDate the flight's departure date
 * @param arrivalDate the flight's arrival date
 * @param origin the flight's origin
 * @param destination the flight's destination
 */
Flight::Flight(string number, string flightDepartureDate, string flightArrivalDate, string flightOrigin,
               string flightDestination) : numberOfFlight(number) , departureDate(flightDepartureDate), origin(flightOrigin){
    this->arrivalDate = flightArrivalDate;
    this->destination = flightDestination;
    this->boughtTickets = 0;
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
string Flight::getDepartureDate() const{
    return departureDate;
}

/**
 * @return the flight's arrival date
 */
string Flight::getArrivalDate() const{
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

