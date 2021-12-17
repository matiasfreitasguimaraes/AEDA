#include "airportSystem/flight.h"
#include "airportSystem/flightManager.h"


int main() {
    FlightManager manageFlight;
    ifstream fileF("flight.txt");
    manageFlight.readFlights(fileF);
    manageFlight.showFlights();
}
