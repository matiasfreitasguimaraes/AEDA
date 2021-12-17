#include <iostream>
#include "airportSystem/flightManager.h"

using namespace std;

int main() {
    string filename = "flights.txt";
    FlightManager flightManager;
    flightManager.readFlights(filename);
    flightManager.showFlights();
    cout << "no additions" << endl;
    DateTime departure(2021, 12, 17, 1, 25);
    DateTime arrival(2021, 12, 17, 2, 25);
    string num = "123", origin = "Porto", destination = "vlc";
    unsigned id = 2;
    Flight flight(num, departure, arrival, origin, destination, id);
    flightManager.addFlight(flight, filename);
    cout << "added flight" << endl;
    flightManager.showFlights();

    flightManager.removeFlight(flight, filename);
    cout << "removed flight" << endl;
    flightManager.showFlights();

    return 0;
}