#include "groundTransport.h"

GroundTransport::GroundTransport(string itsName, string typeName, set<DateTime> sched, double airDis)
    : name(itsName), type(typeName), airportDistance(airDis), schedule(sched) {}

/**
 * @return the type of ground transport
 */
string GroundTransport::getType() const {
    return this->type;
}

/**
 * @return the distance from the airport to the ground transport
 */
double GroundTransport::getAirportDistance() const {
    return this->airportDistance;
}

/**
 * @brief adds date to the schedule
 * @param newDate date to add to the schedule
 */
void GroundTransport::addToSchedule(DateTime newDate) {
    this->schedule.insert(newDate);
}

/**
 * @param date date to remove from schedule
 */
void GroundTransport::removeFromSchedule(DateTime date) {
    this->schedule.erase(date);
}

/**
 * @param out output stream
 * @param groundTransport groundTransport instance
 * @return all the information related to a ground transport
 */
ostream& operator<<(ostream &out, const GroundTransport &groundTransport) {
    out << groundTransport.getType() << " station." << endl;
    out << "Schedule:" << endl;
    for (DateTime date : groundTransport.schedule) {
        out << setfill('0') << setw(2) << date.getHour() << ":"
        << setfill('0') << setw(2) << date.getMinute() << " ";
    }
    out << endl;
    out << "Distance: " << groundTransport.getAirportDistance() << " meters from the airport." << endl;
    return out;
}

bool GroundTransport::operator<(const GroundTransport &rhs) const {
    return airportDistance < rhs.airportDistance;
}

bool GroundTransport::operator>(const GroundTransport &rhs) const {
    return rhs < *this;
}

bool GroundTransport::operator<=(const GroundTransport &rhs) const {
    return !(rhs < *this);
}

bool GroundTransport::operator>=(const GroundTransport &rhs) const {
    return !(*this < rhs);
}

bool GroundTransport::operator==(const GroundTransport &rhs) const {
    return this->name == rhs.name;
}

string GroundTransport::getName() const {
    return name;
}