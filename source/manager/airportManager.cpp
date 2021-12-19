//
// Created by jpdat on 18/12/21.
//

#include <fstream>
#include "airportManager.h"

airportManager::airportManager() {}

int airportManager::add(Airport newAirport) {
    if (airports.find(newAirport) != airports.end())
        return 0;
    airports.insert(newAirport);
    return 1;
}

int airportManager::remove(Airport airportToRemove) {
    if (airports.find(airportToRemove) == airports.end())
        return 0;
    airports.erase(airports.find(airportToRemove));
    return 1;
}

void airportManager::list() {
    if (airports.empty()) {
        cout << "Weird... Not a single airport found. Maybe you want to add some.\n";
    } else {
        for (Airport airport : airports) {
            cout << "- " << airport.getName() << '\n';
        }
    }
}

bool airportManager::find(Airport airport) {
    return (airports.find(airport) != airports.end());
}

set<Airport>& airportManager::get() {
    return airports;
}

void airportManager::write() {
    ofstream file;
    file.open("airports.txt");
    for (Airport airport : airports) {
        file << airport.getName() << "\n";
        file << airport.getGTBST().size() << "\n";
        for (GroundTransport GT : airport.getGTBST()) {
            file << GT.getName() << "\n";
            file << GT.getType() << " " << GT.getAirportDistance() << " " << GT.getSchedule().size() << "\n";
            for (DateTime time : GT.getSchedule()) {
                file << time.getHour() << " " << time.getMinute() << " ";
            }

        }
        file << "\n";
    }
}

int airportManager::read() {
    ifstream airportFile;
    airportFile.open("airports.txt");
    string airportName, GTName, GTType;
    int schedSize, GTBSTSize, airDis, hour, minute;
    while (!airportFile.eof()) {
        getline(airportFile, airportName);
        Airport newAirport = Airport(airportName);
        airportFile >> GTBSTSize;
        for (int i = 0; i < GTBSTSize; i++) {
            getline(airportFile, GTName);
            airportFile >> GTType >> airDis;
            GroundTransport newGT = GroundTransport(GTName, GTType, airDis);
            airportFile >> schedSize;
            for (int j = 0; j < schedSize; j++) {
                airportFile >> hour >> minute;
                newGT.addToSchedule(DateTime(hour, minute));
            }
            newAirport.addGT(newGT);
        }
        airports.insert(newAirport);
    }
    return 1;
}