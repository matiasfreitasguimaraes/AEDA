#include "../source/objects/airport.h"
#include "../source/manager/airportManager.h"

int main() {
    airportMananger manageAirport;
    ifstream fileA("./input/airport.txt");
    manageAirport.read(fileA);
    manageAirport.show();
}