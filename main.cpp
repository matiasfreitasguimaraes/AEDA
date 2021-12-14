#include <iostream>
#include <algorithm>
#include "airportSystem/plane.h"
#include "airportSystem/flight.h"

using namespace std;

void readInputData(ifstream &file) {
    unsigned nPlanes;
    file >> nPlanes;
    vector<Plane> PlanesVec;

    file.open("input.txt", ios::in);

    for (unsigned i = 0; i < nPlanes; ++i) {
        int nFlights;
        file >> nFlights;
        vector<Flight> flightVec;
        string planeRegis;
        string planeType;
        int capacity;

        file >> planeType >> planeRegis >> capacity;
        Plane plane(capacity, planeType, planeRegis);

        for (int j = 0; j < nFlights; ++j) {
            string flightCode;
            string apertureData;
            string arrivalData;
            string apertureLocal;
            string arrivalLocal;

            file >> flightCode >> apertureData >> arrivalData >> apertureLocal >> arrivalLocal;
            flightVec.push_back(Flight(flightCode, apertureData, arrivalData, apertureLocal, arrivalLocal, plane));
        }
        plane.setListOfFlights(flightVec);
        PlanesVec.push_back(plane);
    }
}

int main() {
    ifstream myFile;

    readInputData(myFile);
    return 0;
}
