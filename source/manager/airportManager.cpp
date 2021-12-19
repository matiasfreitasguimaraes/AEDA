#include <fstream>

#include "airportManager.h"

airportManager::airportManager() {}

/**
 * @brief adds a new airport if it not exists already
 * @param newAirport the airport to be added
 * @return 1 if successfully, 0 otherwise
 */
int airportManager::add(Airport newAirport) {
    if (airports.find(newAirport) != airports.end())
        return 0;
    airports.insert(newAirport);
    return 1;
}

/**
 * @brief removes an airport
 * @param airportToRemove airport to be removed
 * @return 1 if successfully, 0 otherwise
 */
int airportManager::remove(Airport airportToRemove) {
    if (airports.find(airportToRemove) == airports.end())
        return 0;
    airports.erase(airports.find(airportToRemove));
    return 1;
}

/**
 * @brief list all the airports' names
 */
void airportManager::listAirports() {
    if (airports.empty()) {
        cout << "Weird... Not a single airport found. Maybe you want to add some.\n";
    } else {
        for (Airport airport : airports) {
            cout << "- " << airport.getName() << '\n';
        }
    }
}

/**
 * @brief finds an airport
 * @param airport the airport to be found
 * @return true if found, false otherwise
 */
bool airportManager::findAirport(Airport airport) {
    return (airports.find(airport) != airports.end());
}

/**
 * @return the set of airports
 */
set<Airport>& airportManager::getAirports() {
    return airports;
}

/**
 * @brief saves the changes made to a file
 */
void airportManager::write() { // TODO: passar ofstream por argumento
    ofstream file;
    file.open("airports.txt");
    for (Airport airport : airports) {
        file << airport.getName() << "\n";
        file << airport.getGTBST().size();
        for (GroundTransport GT : airport.getGTBST()) {
            file << GT.getName() << "\n";
            file << GT.getType() << " " << GT.getAirportDistance() << " " << GT.getSchedule().size() << "\n";
            for (DateTime time : GT.getSchedule()) {
                file << setw(2) << setfill('0') << time.getHour() << " " << setw(2) << setfill('0') << time.getMinute() << " ";
            }
            file << "\n";
        }
    }
}

/**
 * @brief reads the airports' information from a file
 */
void airportManager::read() { //TODO: passar o ifstream por argumento
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
            airportFile >> GTType >> airDis >> schedSize;
            GroundTransport newGT = GroundTransport(GTName, GTType, airDis);
            for (int j = 0; j < schedSize; j++) {
                airportFile >> hour >> minute;
                newGT.addToSchedule(DateTime(hour, minute));
            }
            newAirport.addGT(newGT);
        }
        airports.insert(newAirport);
    }
}
