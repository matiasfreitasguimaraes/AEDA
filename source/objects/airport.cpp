#include "airport.h"

Airport::Airport(string airportName) : name(airportName) {}

/**
 * @return the airport's name
 */
string Airport::getName() {
    return name;
}

/**
 * @param rhs instance of Airport
 * @return the airports with lower name
 */
bool Airport::operator<(const Airport &rhs) const {
    return name < rhs.name;
}

/**
 * @param rhs instance of airport
 * @return true if two airports have the same name
 */
bool Airport::operator==(const Airport &rhs) const {
    return name == rhs.name;
}

/**
 * @brief shows ground transports
 */
void Airport::showGTs() {

    if (groundTransport.empty())
        cout << "Well, there's no transport service registered to be near this airport. Maybe you want to register some?\n";
    else {
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
 * @brief removes a ground transport
 * @param GT ground transport to be removed
 */
void Airport::removeGT(GroundTransport GT) {
    groundTransport.erase(GT);
}

/**
 * @param GTName ground transport's name to be returned
 * @return the ground transport with name GTName
 */
GroundTransport& Airport::getGT(string GTName) {
    set<GroundTransport>::iterator iter = groundTransport.find(GroundTransport(GTName));
    return const_cast<GroundTransport &>(*iter);
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
set<GroundTransport>& Airport::get() {
    return groundTransport;
}
