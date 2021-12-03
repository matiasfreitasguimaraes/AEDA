//
// Created by jpdat on 01/12/21.
//

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
    // schedule is sorted in every addToSchedule call's end and in constructor.
    vector<Date> schedule;
public:
    GroundTransport(string itsName, string typeName, vector<Date> sched, double airDis);
    string getName() const;
    string getType() const;
    double getAirportDistance() const;
    // sorts the schedule.
    void sortSchedule();
    void addToSchedule(Date newDate);
    // removeFromSchedule returns 1 if a date was removed, returns 0 otherwise.
    int removeFromSchedule(Date date);
    friend ostream& operator<<(ostream &out, const GroundTransport &groundTransport);
};


#endif //AEDAPROJECT_GROUNDTRANSPORT_H
