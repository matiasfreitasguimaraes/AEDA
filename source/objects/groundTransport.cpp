#include "groundTransport.h"

GroundTransport::GroundTransport(string itsName, string typeName, set<DateTime> sched, unsigned airDis)
    : name(itsName), type(typeName), airportDistance(airDis), schedule(sched) {}

GroundTransport::GroundTransport(string itsName) : name(itsName) {}

GroundTransport::GroundTransport(string itsName, string itsType, unsigned airDis) : name(itsName), type(itsType), airportDistance(airDis) {}

/**
 * @return the type of ground transport
 */
string GroundTransport::getType() const {
    return type;
}

/**
 * @return the distance from the airport to the ground transport
 */
unsigned GroundTransport::getAirportDistance() const {
    return airportDistance;
}

/**
 * @brief adds date to the schedule
 * @param newDate date to add to the schedule
 */
void GroundTransport::addToSchedule(DateTime newDate) {
    schedule.insert(newDate);
}

/**
 * @param date date to remove from schedule
 */
void GroundTransport::removeFromSchedule(DateTime date) {
    schedule.erase(date);
}

/**
 * @param out output stream
 * @param groundTransport groundTransport instance
 * @return all the information related to a ground transport
 */
ostream& operator<<(ostream &out, const GroundTransport &groundTransport) {
    out << groundTransport.getName() << " " << groundTransport.getType() << " station." << endl;
    out << "Schedule:" << endl;

    for (DateTime date : groundTransport.schedule) {
        out << setfill('0') << setw(2) << date.getHour() << ":"
        << setfill('0') << setw(2) << date.getMinute() << " ";
    }
    out << endl;
    out << "Distance: " << groundTransport.getAirportDistance() << " meters from the airport." << endl;
    return out;
}

/**
 * @return the ground transport's name
 */
string GroundTransport::getName() const {
    return name;
}

/**
 * @param rhs instance of GroundTransport
 * @return the ground transport closer to the airport
 */
bool GroundTransport::operator<(const GroundTransport &rhs) const {
    return name < rhs.getName();
}

/**
 * @param rhs instance of GroundTransport
 * @return true if two ground transports have the same name
 */
bool GroundTransport::operator==(const GroundTransport &rhs) const {
    return name == rhs.getName();
}

/**
 * @brief shows the ground transport's schedule
 */
void GroundTransport::showSched() {

    if (schedule.empty())
        cout << "Seems like there's no schedule registered for this transport service.\n";
    else {
        for (DateTime time : schedule) {
            cout << "- " << time.getHour() << ":" << time.getMinute() << "\n";
        }
    }
}

/**
 * @return the set of schedules
 */
set<DateTime> & GroundTransport::getSchedule() {
    return schedule;
}

/**
 * @param date date to be found in transport's schedule
 * @return true if found, false otherwise
 */
bool GroundTransport::findInSchedule(DateTime date) {

    for (DateTime dat:schedule) {
        if(dat == date){
            return true;
        }
    }
    return false;
}
