#ifndef AEDAPROJECT_FLIGHT_H
#define AEDAPROJECT_FLIGHT_H

#include <string>
#include <iostream>
#include <vector>
#include "passenger.h"
#include "dateTime.h"


using namespace std;

class Flight {
private:
    string numberOfFlight;
    DateTime departureDate;
    DateTime arrivalDate;
    string origin;
    string destination;
    string nexPlane;
    unsigned int boughtTickets;
public:
    Flight(string &number, DateTime &flightDepartureDate, DateTime &flightArrivalDate,
           string &flightOrigin, string &flightDestination, string nextPlane);
    string getNumberOfFlight() const;
    DateTime getDepartureDate() const;
    DateTime getArrivalDate() const;
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
