#include "ticket.h"

Ticket::Ticket(Flight &flight1, Passenger pass) : flight(flight1) {
    this->passenger = pass;
}

/**
 * @return the flight for which the ticket is
 */
Flight Ticket::getFlight() const {
    return flight;
}

/**
 * @return the passenger who owns the ticket
 */
Passenger Ticket::getPassenger() const {
    return passenger;
}

/**
 * @param out output stream
 * @param t1 instance of Ticket
 * @return all the ticket information
 */
ostream& operator<<(ostream &out, const Ticket &t1) {
    out << "Owner: " << t1.getPassenger() << endl;
    out << "Flight: " << t1.getFlight() << endl;
    return out;
}