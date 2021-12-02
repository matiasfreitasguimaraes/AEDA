//
// Created by jpdat on 01/12/21.
//

#include "groundTransport.h"

GroundTransport::GroundTransport(string itsName, string typeName, vector<Date> sched, double airDis) : name(itsName), type(typeName), airportDistance(airDis) {
    this->schedule = sched;
}

string GroundTransport::getName() const {
    return this->name;
}

string GroundTransport::getType() const {
    return this->type;
}

double GroundTransport::getAirportDistance() const {
    return this->airportDistance;
}

void GroundTransport::sortSchedule() {
    sort(schedule.begin(), schedule.end());
}

void GroundTransport::addToSchedule(Date newDate) {
    this->schedule.push_back(newDate);
    sortSchedule();
}

int GroundTransport::removeFromSchedule(Date date) {
    return -1;
}

ostream& operator<<(ostream &out, const GroundTransport &groundTransport) {
    out << groundTransport.getName() << " " << groundTransport.getType() << "station." << endl;
    out << "Schedule:" << endl;
    for (Date date : groundTransport.schedule) {
        out << date.hour << ":" << date.minute << " ";
    }
    out << endl;
    out << "Distance: " << groundTransport.getAirportDistance() << " meters from the airport." << endl;
    return out;
}