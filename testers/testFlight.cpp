#include "../source/objects/flight.h"
#include "../source/manager/flightManager.h"


int main() {
    FlightManager manageFlight;
    ifstream fileF("./input/flight.txt");
    manageFlight.read(fileF);
    manageFlight.show();
}
