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
        cout << "oi";
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
        for (int j = 0; j < nFlights; ++j) {
            string flightCode;
            string apertureData;
            string arrivalData;
            string apertureLocal;
            string arrivalLocal;
            myfile >> flightCode;
            myfile >> apertureData;
            myfile >> arrivalData;
            myfile >> apertureLocal;
            myfile >> arrivalLocal;
            FlightVec.push_back(Flight(flightCode, apertureData, arrivalData, apertureLocal, arrivalLocal));
        }
        myfile >> planeRegis;
        myfile >> planeType;
        myfile >> capacity;
        PlanesVec.push_back(Plane(capacity, planeType, planeRegis, FlightVec));
    }
    for(auto plane: PlanesVec){
        cout << plane;
    }
    return 0;
}