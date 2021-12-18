//
// Created by jpdat on 18/12/21.
//

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

void airportManager::listAirports() {
    if (airports.empty()) {
        cout << "Weird... Not a single airport found. Maybe you want to add some.\n";
    } else {
        for (Airport airport : airports) {
            cout << "- " << airport.getName() << '\n';
        }
    }
}

bool airportManager::findAirport(Airport airport) {
    return (airports.find(airport) != airports.end());
}
