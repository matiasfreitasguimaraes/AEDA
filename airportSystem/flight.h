//
// Created by Matias Freitas Guimarães on 29/11/2021.
//

#ifndef AEDAPROJECT_FLIGHT_H
#define AEDAPROJECT_FLIGHT_H

#include <string>
#include <iostream>
#include <iostream>

using namespace std;

class Flight {
private:
    unsigned numberOfFlight;
    string departureDate;
    string arrivalDate;
    string origin;
    string destination;
public:
    Flight();
    Flight(unsigned number, string flightDepartureDate, string flightArrivalDate, string flightOrigin, string flightDestination);
    unsigned getNumberOfFlight() const;
    string getDepartureDate() const;
    string getArrivalDate() const;
    string getOrigin() const;
    string getDestination() const;
    void setNumberOfFlight(unsigned number);
    void setDepartureDate(string flightDepartureDate);
    void setArrivalDate(string flightArrivalDate);
    void setOrigin(string flightOrigin);
    void setDestination(string flightDestination);
    friend ostream& operator<<(ostream &out, const Flight &flight);
};


#endif //AEDAPROJECT_FLIGHT_H