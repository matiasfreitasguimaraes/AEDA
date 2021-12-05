#ifndef AEDAPROJECT_FLIGHT_H
#define AEDAPROJECT_FLIGHT_H

#include <string>
#include <iostream>
#include "plane.h"


using namespace std;

class Flight {
private:
    string numberOfFlight;
    string departureDate;
    string arrivalDate;
    string origin;
    string destination;
    unsigned int boughtTickets;
    Plane assignedPlane:
public:
    Flight(string number, string flightDepartureDate, string flightArrivalDate, string flightOrigin, string flightDestination, Plane plane);
    string getNumberOfFlight() const;
    string getDepartureDate() const;
    string getArrivalDate() const;
    string getOrigin() const;
    string getDestination() const;
    void setDestination(string flightDestination);
    friend ostream& operator<<(ostream &out, const Flight &flight);
    void updateBoughtTickets(int nTickets);
    unsigned getnumberOfTicketsBought() const;
    bool canBuyTicket();
};


#endif //AEDAPROJECT_FLIGHT_H
