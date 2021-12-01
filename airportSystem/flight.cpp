//
// Created by Matias Freitas Guimarães on 29/11/2021.
//

#include <iostream>
#include "flight.h"

using namespace std;

/**
 * @brief default constructor
 */
Flight::Flight() {
    this->numberOfFlight = -1;
    this->departureDate = "";
    this->arrivalDate = "";
    this->origin = "";
    this->destination = "";
}

/**
 * @param numberOfFlight the flight's number
 * @param departureDate the flight's departure date
 * @param arrivalDate the flight's arrival date
 * @param origin the flight's origin
 * @param destination the flight's destination
 */
Flight::Flight(unsigned int numberOfFlight, string departureDate, string arrivalDate, string origin,
               string destination) {
    this->numberOfFlight = numberOfFlight;
    this->departureDate = departureDate;
    this->arrivalDate = arrivalDate;
    this->origin = origin;
    this->destination = destination;
}

/**
 * @return the flight's origin
 */
string Flight::getOrigin() const {
    return origin;
}

/**
 * @return the flight's destination
 */
string Flight::getDestination() const {
    return destination;
}

/**
 * @return the flight's departure date
 */
string Flight::getDepartureDate() const {
    return departureDate;
}

/**
 * @return the flight's arrival date
 */
string Flight::getArrivalDate() const {
    return arrivalDate;
}

/**
 * @return the flight's number
 */
unsigned int Flight::getNumberOfFlight() const {
    return numberOfFlight;
}

/**
 * @param arrivalDate the flight's new arrival date in format dd/mm/yyyy
 */
void Flight::setArrivalDate(string arrivalDate) {
    this->arrivalDate = arrivalDate;
}

/**
 * @param departureDate the flight's new departure date in format dd/mm/yyyy
 */
void Flight::setDepartureDate(string departureDate) {
    this->departureDate = departureDate;
}

/**
 * @param destination the flight's new destination
 */
void Flight::setDestination(string destination) {
    this->destination = destination;
}

/**
 * @param origin the flight's new origin
 */
void Flight::setOrigin(string origin) {
    this->origin = origin;
}

/**
 * @param numberOfFlight the flight's new number
 */
void Flight::setNumberOfFlight(unsigned int numberOfFlight) {
    this->numberOfFlight = numberOfFlight;
}

/**
 * @param out output stream
 * @param flight instance of Flight
 * @return all the flight information
 */
ostream& operator<<(ostream &out, const Flight flight) {
    out << "Flight number: " << flight.getNumberOfFlight() << endl;
    out << "Flight's departure date: " << flight.getDepartureDate() << endl;
    out << "Flight's arrival date: " << flight.getArrivalDate() << endl;
    out << "Flight's origin: "  << flight.getOrigin() << endl;
    out << "Flight's destination: " << flight.getDestination() << endl;
}