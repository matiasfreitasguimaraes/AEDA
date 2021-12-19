#include "ticket.h"

Ticket::Ticket(Flight &flight1, Passenger pass) : passenger(pass), flight(flight1) {}

/**
 * @return the flight the ticket corresponds
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
 * @param t1 instance of ticket
 * @return all the information related to a ticket
 */
ostream& operator<<(ostream &out, const Ticket &t1) {
    out << "Owner: " << t1.getPassenger() << endl;
    out << "Flight: " << t1.getFlight() << endl;
    return out;
}
