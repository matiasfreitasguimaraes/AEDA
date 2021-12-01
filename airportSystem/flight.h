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
    string getNumberOfFlight();
    unsigned getNumberOfInstances();
    string getDepartureDate();
    string getArrivalDate();
    string getOrigin();
    string getDestination();
    void setNumberOfFlight(string number);
    void setDepartureDate(string flightDepartureDate);
    void setArrivalDate(string flightArrivalDate);
    void setOrigin(string flightOrigin);
    void setDestination(string flightDestination);
    friend ostream& operator<<(ostream &out, Flight &flight);
};


#endif //AEDAPROJECT_FLIGHT_H
