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
    vector<date> schedule;
public:
    GroundTransport(string itsName, string typeName, vector<date> sched, double airDis);
    string getName() const;
    string getType() const;
    double getAirportDistance() const;
    void sortSchedule();
    void addToSchedule(date newTime);
    void removeFromSchedule(int hour, int minutes);
    friend ostream& operator<<(ostream &out, const GroundTransport &groundTransport);
};


#endif //AEDAPROJECT_GROUNDTRANSPORT_H
