#ifndef AEDAPROJECT_GROUNDTRANSPORT_H
#define AEDAPROJECT_GROUNDTRANSPORT_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
#include "dateTime.h"

using namespace std;

class GroundTransport {
    string name;
    string type;
    unsigned airportDistance;
    set<DateTime> schedule;
public:
    GroundTransport(string itsName, string typeName, set<DateTime> sched, unsigned airDis);
    GroundTransport(string itsName);
    GroundTransport(string itsName, string itsType, unsigned airDis);
    string getName() const;
    string getType() const;
    unsigned getAirportDistance() const;
    set<DateTime> & getSchedule() ;
    void showSched();
    void addToSchedule(DateTime newDate);
    void removeFromSchedule(DateTime date);
    friend ostream& operator<<(ostream &out, const GroundTransport &groundTransport);
    bool operator<(const GroundTransport &rhs) const;
    bool operator==(const GroundTransport &rhs) const;
};

#endif //AEDAPROJECT_GROUNDTRANSPORT_H
