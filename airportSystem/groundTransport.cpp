//
// Created by jpdat on 01/12/21.
//

#include "groundTransport.h"

GroundTransport::GroundTransport(string itsName, string typeName, vector<date> sched, double airDis) : name(itsName), type(typeName), airportDistance(airDis) {
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

void GroundTransport::addToSchedule(date newTime) {
    this->schedule.push_back(newTime);
    sortSchedule();
}

void GroundTransport::removeFromSchedule(int hour, int minutes) {
    for (unsigned i = 0; i < schedule.size(); i++) {
        if (schedule[i].tm_hour == hour && schedule[i].tm_min == minutes)
            schedule.erase(schedule.begin() + i);
    }
}

ostream& operator<<(ostream &out, const GroundTransport &groundTransport) {
    out << groundTransport.getName() << " " << groundTransport.getType() << "station." << endl;
    out << "Schedule:" << endl;
    for (tm time : groundTransport.schedule) {
        out << time.tm_hour << ":" << time.tm_min << " ";
    }
    out << endl;
    out << "Distance: " << groundTransport.getAirportDistance() << " meters from the airport." << endl;
    return out;
}