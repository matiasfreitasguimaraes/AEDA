#ifndef AEDAPROJECT_GROUNDTRANSPORT_H
#define AEDAPROJECT_GROUNDTRANSPORT_H

#include <string>
#include <vector>
#include <iostream>
#include "date.h"

using namespace std;

class GroundTransport {
    const string name;
    const string type;
    const double airportDistance;
    vector<Date> schedule;
public:
    GroundTransport(string itsName, string typeName, vector<Date> sched, double airDis);
    string getName() const;
    string getType() const;
    double getAirportDistance() const;
    void sortSchedule();
    void addToSchedule(Date newDate);
    int removeFromSchedule(Date date);
    friend ostream& operator<<(ostream &out, const GroundTransport &groundTransport);
};


#endif //AEDAPROJECT_GROUNDTRANSPORT_H
