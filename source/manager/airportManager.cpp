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

void airportManager::write(ofstream& file) {
    for (Airport airport : airports) {
        file << airport.getName() << " "
             << airport.getGT().size();
        for (GroundTransport GT : airport.getGT()) {
            file << GT.getName() << "\n";
            file << GT.getType() << " " << GT.getAirportDistance() << " " << GT.getSchedule().size() << "\n";
            for (DateTime time : GT.getSchedule()) {
                file << setw(2) << setfill('0') << time.getHour() << " " << setw(2) << setfill('0') << time.getMinute() << " ";
            }

        }
        file << "\n";
    }
}

void airportManager::read(ifstream &file) {
    string airportName, GTName, GTType;
    int schedSize, GTBSTSize, airDis, hour, minute;
    while (file.peek() != EOF) {
        file >> airportName >> GTBSTSize;
        Airport newAirport = Airport(airportName);
        for (int i = 0; i < GTBSTSize; i++) {
            file >> GTType >> airDis;
            GroundTransport newGT = GroundTransport(GTName, GTType, airDis);
            file >> schedSize;
            for (int j = 0; j < schedSize; j++) {
                file >> hour >> minute;
                newGT.addToSchedule(DateTime(hour, minute));
            }
            newAirport.addGT(newGT);
        }
        airports.insert(newAirport);
    }
}