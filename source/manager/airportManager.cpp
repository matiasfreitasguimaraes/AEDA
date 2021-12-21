#include "airportManager.h"

/**
 * @brief adds a new airport
 * @param newAirport the airport to be added
 * @return 1 if successfully, false otherwise
 */
int AirportManager::add(Airport newAirport) {

    if (airports.find(newAirport) != airports.end())
        return 0;
    airports.insert(newAirport);
    return 1;
}

/**
 * @brief removes an airport
 * @param airportToRemove airport to be removed
 * @return 1 if successfully, false otherwise
 */
int AirportManager::remove(Airport airportToRemove) {

    if (airports.find(airportToRemove) == airports.end())
        return 0;
    airports.erase(airports.find(airportToRemove));
    return 1;
}

/**
 * @brief displays all the airports
 */
void AirportManager::show() {

    if (airports.empty()) {
        cout << "Weird... Not a single airport found. Maybe you want to add some.\n";
    } else {
        for (Airport airport : airports) {
            cout << "- " << airport.getName() << '\n';
        }
    }
}

/**
 * @param airport the airport to be found
 * @return true if found, false otherwise
 */
bool AirportManager::find(Airport airport) {
    return (airports.find(airport) != airports.end());
}

/**
 * @return the set of airports
 */
set<Airport>& AirportManager::get() {
    return airports;
}

/**
 * @brief writes the changes made to a file
 * @param file the file in which the changes are saved
 */
void AirportManager::write(ofstream& file) {

    for (Airport airport : airports) {
        file << airport.getName() << " "
             << airport.get().size();

        for (GroundTransport GT : airport.get()) {
            file << endl << GT.getName() << endl;
            file << GT.getType() << " " << GT.getAirportDistance() << " " << GT.getSchedule().size() << endl;

            for (DateTime time : GT.getSchedule()) {
                file << setw(2) << setfill('0') << time.getHour() << " " << setw(2) << setfill('0') << time.getMinute() << " ";
            }
        }
        file << endl;
    }
}

/**
 * @brief reads airport information from a file
 * @param file the file to read the information from
 */
void AirportManager::read(ifstream &file) {
    string airportName, GTName, GTType;
    int schedSize, GTBSTSize, airDis, hour, minute;

    while (file.peek() != EOF) {
        file >> airportName >> GTBSTSize;
        Airport newAirport = Airport(airportName);

        for (int i = 0; i < GTBSTSize; i++) {
            file.ignore(100, '\n');
            getline(file,GTName);
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
