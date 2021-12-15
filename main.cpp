#include <iostream>
#include <algorithm>

#include "airportSystem/plane.h"
#include "airportSystem/flight.h"

using namespace std;

void readInputData(string filename) {
    ifstream input;
    input.open(filename, ios::in);

    unsigned nPlanes;
    input >> nPlanes;
    vector<Plane> PlanesVec;

    for (unsigned i = 0; i < nPlanes; ++i) {
        int nFlights;
        input >> nFlights;
        vector<Flight> flightVec;
        string planeRegis;
        string planeType;
        int capacity;

        input >> planeType >> planeRegis >> capacity;
        Plane plane(capacity, planeType, planeRegis);

        for (int j = 0; j < nFlights; ++j) {
            string flightCode;
            string apertureData;
            string arrivalData;
            string apertureLocal;
            string arrivalLocal;

            input >> flightCode >> apertureData >> arrivalData >> apertureLocal >> arrivalLocal;
            flightVec.push_back(Flight(flightCode, apertureData, arrivalData, apertureLocal, arrivalLocal, plane));
        }
        plane.setListOfFlights(flightVec);
        PlanesVec.push_back(plane);
    }
}

int main() {
    const string planesAndFlights = "input.txt";

    readInputData(planesAndFlights);
    return 0;
}
