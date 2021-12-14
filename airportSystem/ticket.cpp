#include "ticket.h"

Ticket::Ticket(Flight &flight1, Passenger pass) : flight(flight1) {
    this->passenger = pass;
}

Flight Ticket::getFlight() const {
    return flight;
}

Passenger Ticket::getPassenger() const {
    return passenger;
}
