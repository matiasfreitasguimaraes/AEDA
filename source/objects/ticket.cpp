#include "ticket.h"

Ticket::Ticket(Flight &flight1, Passenger pass) : passenger(pass), flight(flight1) {}

Flight Ticket::getFlight() const {
    return flight;
}

Passenger Ticket::getPassenger() const {
    return passenger;
}

ostream& operator<<(ostream &out, const Ticket &t1) {
    out << "Owner: " << t1.getPassenger() << endl;
    out << "Flight: " << t1.getFlight() << endl;
    return out;
}