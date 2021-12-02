#ifndef AEDAPROJECT_FLIGHT_H
#define AEDAPROJECT_FLIGHT_H

#include <string>
#include <iostream>

using namespace std;

class Flight {
private:
    string numberOfFlight;
    string departureDate;
    string arrivalDate;
    string origin;
    string destination;
    static unsigned instances;
public:
    Flight(string number, string flightDepartureDate, string flightArrivalDate, string flightOrigin, string flightDestination);
    string getNumberOfFlight() const;
    unsigned getNumberOfInstances() const;
    string getDepartureDate() const;
    string getArrivalDate() const;
    string getOrigin() const;
    string getDestination() const;
    void setNumberOfFlight(string number);
    void setDepartureDate(string flightDepartureDate);
    void setArrivalDate(string flightArrivalDate);
    void setOrigin(string flightOrigin);
    void setDestination(string flightDestination);
    friend ostream& operator<<(ostream &out, const Flight &flight);
};


#endif //AEDAPROJECT_FLIGHT_H
