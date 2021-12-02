//
// Created by jpdat on 01/12/21.
//

#ifndef AEDAPROJECT_GROUNDTRANSPORT_H
#define AEDAPROJECT_GROUNDTRANSPORT_H

#include <string>
#include <ctime>
#include <vector>

using namespace std;

class GroundTransport {
    const string type;
    const double airportDistance;
    vector<tm> schedule;
public:
    GroundTransport(string typeName, vector<tm> sched, double airDis);
    string getType() const;
    double getAirportDistance() const;
    void sortSchedule();
    void addToSchedule(tm newTime);
    void removeFromSchedule(int hour, int minutes);
};


#endif //AEDAPROJECT_GROUNDTRANSPORT_H
