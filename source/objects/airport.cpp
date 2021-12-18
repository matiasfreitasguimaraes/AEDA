#include "airport.h"

Airport::Airport(string airportName) : name(airportName) {}

string Airport::getName() {
    return this->name;
}

bool Airport::operator<(const Airport &rhs) const {
    return this->name < rhs.name;
}

bool Airport::operator==(const Airport &rhs) const {
    return this->name == rhs.name;
}

void Airport::showGTs() {
    if (groundTransportBST.empty()) {
        cout << "Well, there's no transport service registered to be near this airport. Maybe you want to register some?\n";
    } else {
        for (GroundTransport GT : groundTransportBST) {
            cout << "- " << GT.getName() << "\n";
        }
    }
}

void Airport::addGT(GroundTransport GT) {
    groundTransportBST.insert(GT);
}

/*void Airport::addLuggageCar(LuggageCar &car) {
    luggageCars.push_back(car);
}*/

GroundTransport Airport::getGT(string GTName) {
    set<GroundTransport>::iterator iter = groundTransportBST.find(GroundTransport(GTName));
    return *iter;
}

bool Airport::findGT(string GTName) {
    return groundTransportBST.find(GroundTransport(GTName)) != groundTransportBST.end();
}

set<GroundTransport> Airport::getGTBST() {
    return groundTransportBST;
}
