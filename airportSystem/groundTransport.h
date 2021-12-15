#ifndef AEDAPROJECT_GROUNDTRANSPORT_H
#define AEDAPROJECT_GROUNDTRANSPORT_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#include "date.h"

using namespace std;

class GroundTransport {
    const string name;
    const string type;
    const double airportDistance;
    vector<Date> schedule;
public:
    GroundTransport();
    GroundTransport(string itsName, string typeName, vector<Date> sched, double airDis);
    string getName() const;
    string getType() const;
    double getAirportDistance() const;
    void sortSchedule();
    void addToSchedule(Date newDate);
    void removeFromSchedule(Date date);
    friend ostream& operator<<(ostream &out, const GroundTransport &groundTransport);
    bool operator<(const GroundTransport &g1);
};


#endif //AEDAPROJECT_GROUNDTRANSPORT_H
