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
    string type;
    double airportDistance;
    set<DateTime> schedule;
public:
    GroundTransport(string typeName, set<DateTime> sched, double airDis);
    string getType() const;
    double getAirportDistance() const;
    void addToSchedule(DateTime newDate);
    void removeFromSchedule(DateTime date);
    friend ostream& operator<<(ostream &out, const GroundTransport &groundTransport);
    bool operator<(const GroundTransport &g1);
};


#endif //AEDAPROJECT_GROUNDTRANSPORT_H
