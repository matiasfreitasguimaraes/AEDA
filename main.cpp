//
// Created by Matias Freitas Guimarães on 29/11/2021.
//

#include <iostream>
#include <climits>
#include <algorithm>
#include "airportSystem/plane.h"
#include "airportSystem/flight.h"

using namespace std;
int main() {
    int nPlanes;
    ifstream myfile;
    myfile.open("input.txt", ios::in);
    if(myfile.is_open()){
        cout << "oi\n";
    }
    myfile >> nPlanes;
    vector<Plane> PlanesVec;
    for (int i = 0; i < nPlanes; ++i) {
        int nFlights;
        myfile >> nFlights;
        vector<Flight> FlightVec;
        string planeRegis;
        string planeType;
        int capacity;

        myfile >> planeType >> planeRegis >> capacity;
        Plane plane(capacity, planeType, planeRegis);
        for (int j = 0; j < nFlights; ++j) {
            string flightCode;
            string apertureData;
            string arrivalData;
            string apertureLocal;
            string arrivalLocal;

            myfile >> flightCode >> apertureData >> arrivalData >> apertureLocal >> arrivalLocal;
            FlightVec.push_back(Flight(flightCode, apertureData, arrivalData, apertureLocal, arrivalLocal, plane));
        }
        plane.setListOfFlights(FlightVec);
        PlanesVec.push_back(plane);
    }
    for(auto plane: PlanesVec){
        cout << plane << endl;
    }
    return 0;
}