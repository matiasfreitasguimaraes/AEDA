#ifndef AEDAPROJECT_FLIGHT_H
#define AEDAPROJECT_FLIGHT_H

#include <string>
#include <iostream>
#include <vector>

#include "plane.h"
#include "passenger.h"
#include "date.h"

class Ticket;

using namespace std;

class Flight {
private:
    string numberOfFlight;
    Date departureDate;
    Date arrivalDate;
    string origin;
    string destination;
    unsigned int boughtTickets;
    Plane assignedPlane;
    vector<Ticket> tickets;
public:
    Flight(string &number, Date &flightDepartureDate, Date &flightArrivalDate, string &flightOrigin, string &flightDestination, Plane &plane);
    string getNumberOfFlight() const;
    Date getDepartureDate() const;
    Date getArrivalDate() const;
    string getOrigin() const;
    string getDestination() const;
    void setDestination(string flightDestination);
    void updateBoughtTickets(int nTickets);
    unsigned getNumberOfTicketsBought() const;
    bool canBuyTicket();
    void buyTicket(Passenger &passenger);
    friend ostream& operator<<(ostream &out, const Flight &flight);
};


#endif //AEDAPROJECT_FLIGHT_H
