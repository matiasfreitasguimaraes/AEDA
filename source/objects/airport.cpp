#include "airport.h"

Airport::Airport(string airportName) : name(airportName) {}

/**
 * @return the airport's name
 */
string Airport::getName() {
    return this->name;
}

/**
 * @param rhs instance of airport
 * @return the airports with lower name
 */
bool Airport::operator<(const Airport &rhs) const {
    return this->name < rhs.name;
}

/**
 * @param rhs instance of airport
 * @return true if two airports have the same name
 */
bool Airport::operator==(const Airport &rhs) const {
    return this->name == rhs.name;
}

/**
 * @brief shows ground transports
 */
void Airport::showGTs() {
    if (groundTransport.empty()) {
        cout << "Well, there's no transport service registered to be near this airport. Maybe you want to register some?\n";
    } else {
        for (GroundTransport GT : groundTransport)
            cout << GT << endl;
    }
}

/**
 * @brief adds a ground transport
 * @param GT ground transport instance to be added
 */
void Airport::addGT(GroundTransport GT) {
    groundTransport.insert(GT);
}

/**
 * @param GTName ground transport's name to be returned
 * @return the ground transport with name GTName
 */
GroundTransport Airport::getGT(string GTName) {
    set<GroundTransport>::iterator iter = groundTransport.find(GroundTransport(GTName));
    return *iter;
}

/**
 * @param GTName the ground transport's name to be found
 * @return true if the ground transport was found, false otherwise
 */
bool Airport::findGT(string GTName) {
    return groundTransport.find(GroundTransport(GTName)) != groundTransport.end();
}

/**
 * @return the set of ground transports
 */
set<GroundTransport> Airport::getGT() {
    return groundTransport;
}
