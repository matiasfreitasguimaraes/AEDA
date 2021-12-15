#include <iostream>
#include <sstream>

#include "airportSystem/plane.h"
#include "airportSystem/flight.h"
#include "airportSystem/luggageCar.h"
#include "airportSystem/airport.h"

using namespace std;

/**
 * @brief reads the information related to the planes, flights and services
 * @param filename file containing the information related to the planes
 */
void readInputData(const string &filename) {
    ifstream input;
    input.open(filename, ios::in);

    unsigned nPlanes;
    input >> nPlanes;
    vector<Plane> PlanesVec;

    for (unsigned i = 0; i < nPlanes; ++i) {
        unsigned nFlights, numberOfPastServices, numberOfScheduledServices, capacity;
        unsigned year, month, day, hour, minute;
        char sep;
        vector<Flight> flightVec;
        string planeRegis;
        string planeType;
        string type, responsible;

        input >> nFlights;
        input >> planeType >> planeRegis >> capacity;
        Plane plane(capacity, planeType, planeRegis);

        for (unsigned j = 0; j < nFlights; ++j) {
            string flightCode;
            string apertureLocal;
            string arrivalLocal;
            int apertureDay, apertureMonth, apertureYear, apertureHour, apertureMinute;
            int arrivalDay, arrivalMonth, arrivalYear, arrivalHour, arrivalMinute;

            input >> flightCode >> apertureDay >> sep >> apertureMonth >> sep >> apertureYear >> apertureHour >> sep >> apertureMinute >> arrivalDay >> sep >> arrivalMonth >> sep >> arrivalYear >> arrivalHour >> sep >> arrivalMinute >> apertureLocal >> arrivalLocal;
            Date apertureData(apertureYear, apertureMonth, apertureDay, apertureHour, apertureMinute);
            Date arrivalData(arrivalYear, arrivalMonth, arrivalDay, arrivalHour, arrivalMinute);

            flightVec.push_back(Flight(flightCode, apertureData, arrivalData, apertureLocal, arrivalLocal, plane));
        }
        plane.setListOfFlights(flightVec);

        input >> numberOfPastServices;
        for (unsigned k = 0; k < numberOfPastServices; k++) {
            input >> type >> day >> sep >> month >> sep >> year >> hour >> sep >> minute >> responsible;
            Date d(year, month, day, hour, minute);
            MaintenanceService service(type, d, responsible);
            plane.addPastService(service);
        }
        input >> numberOfScheduledServices;

        for (unsigned l = 0; l < numberOfScheduledServices; l++) {
            input >> type >> day >> sep >> month >> sep >> year >> hour >> sep >> minute >> responsible;
            Date date(year, month, day, hour, minute);
            MaintenanceService scheduledService(type, date, responsible);
            plane.addScheduledService(scheduledService);
        }
        PlanesVec.push_back(plane);
    }
}

/**
 * @brief reads information related to the available luggage cars in the airport
 * @param filename file containing the luggage cars' information
 * @param a instance of Airport
 */
void readLuggageCarsDate(const string &filename, Airport &a) {
    ifstream file(filename, ios::in);
    stringstream line;
    unsigned numberOfCarriages, numberOfPiles, numberOfSuitcasesPerPile;

    while (!file.eof()) {
        file >> numberOfCarriages >> numberOfPiles >> numberOfSuitcasesPerPile;
        LuggageCar car(numberOfCarriages, numberOfPiles, numberOfSuitcasesPerPile);
        a.addLuggageCar(car);
    }
}


int main() {
    const string planesAndFlights = "input.txt";
    const string luggageCarsDate = "luggageCars.txt";

    Airport airport = Airport();

    readInputData(planesAndFlights);
    readLuggageCarsDate(luggageCarsDate, airport);
    return 0;
}
