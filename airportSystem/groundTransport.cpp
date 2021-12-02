//
// Created by jpdat on 01/12/21.
//

#include "groundTransport.h"

GroundTransport::GroundTransport(string typeName, vector<tm> sched, double airDis) : type(typeName), airportDistance(airDis) {
    this->schedule = sched;
}

string GroundTransport::getType() const {
    return this->type;
}

double GroundTransport::getAirportDistance() const {
    return this->airportDistance;
}

void GroundTransport::addToSchedule(tm newTime) {
    this->schedule.push_back(newTime);
}

void GroundTransport::removeFromSchedule(int hour, int minutes) {
    for (unsigned i = 0; i < schedule.size(); i++) {
        if (schedule[i].tm_hour == hour && schedule[i].tm_min == minutes)
            schedule.erase(schedule.begin() + i);
    }

}


