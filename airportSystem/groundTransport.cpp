#include "groundTransport.h"

GroundTransport::GroundTransport(string itsName, string typeName, vector<Date> sched, double airDis)
    : name(itsName), type(typeName), airportDistance(airDis), schedule(sched) {}

/**
 * @return the ground transport name
 */
string GroundTransport::getName() const {
    return this->name;
}

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
 * @brief sorts the schedule from the next transport to arrive to the last
 */
void GroundTransport::sortSchedule() {
    sort(schedule.begin(), schedule.end(), [](Date &d1, Date &d2) { return d1 > d2; });
}

/**
 * @brief adds date to the schedule
 * @param newDate date to add to the schedule
 */
void GroundTransport::addToSchedule(Date newDate) {
    this->schedule.push_back(newDate);
    sortSchedule();
}

/**
 * @param date date to remove from schedule
 */
void GroundTransport::removeFromSchedule(Date date) {
    for (Date &d: schedule) {
        if (date == d)
            std::remove(schedule.begin(), schedule.end(), date);
    }
}

/**
 * @param out output stream
 * @param groundTransport groundTransport instance
 * @return all the information related to a ground transport
 */
ostream& operator<<(ostream &out, const GroundTransport &groundTransport) {
    out << groundTransport.getName() << " " << groundTransport.getType() << "station." << endl;
    out << "Schedule:" << endl;
    for (Date date : groundTransport.schedule) {
        out << date.getHour() << ":" << date.getHour() << " ";
    }
    out << endl;
    out << "Distance: " << groundTransport.getAirportDistance() << " meters from the airport." << endl;
    return out;
}