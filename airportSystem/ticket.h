#ifndef AEDAPROJECT_TICKET_H
#define AEDAPROJECT_TICKET_H

#include "passenger.h"
#include "flight.h"

class Ticket {
private:
    Passenger passenger;
    Flight flight;
public:
    Ticket(Flight &flight1, Passenger pass);
    Passenger getPassenger() const;
    Flight getFlight() const;
};


#endif //AEDAPROJECT_TICKET_H
