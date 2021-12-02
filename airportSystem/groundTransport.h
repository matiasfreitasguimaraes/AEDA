//
// Created by jpdat on 01/12/21.
//

#ifndef AEDAPROJECT_GROUNDTRANSPORT_H
#define AEDAPROJECT_GROUNDTRANSPORT_H

#include <string>
#include <ctime>
#include <vector>
#include <iostream>

using namespace std;

class GroundTransport {
    const string name;
    const string type;
    const double airportDistance;
    vector<tm> schedule;
public:
    GroundTransport(string itsName, string typeName, vector<tm> sched, double airDis);
    string getName() const;
    string getType() const;
    double getAirportDistance() const;
    static bool compareTimes(tm latter, tm sooner);
    void sortSchedule();
    void addToSchedule(tm newTime);
    void removeFromSchedule(int hour, int minutes);
    friend ostream& operator<<(ostream &out, const GroundTransport &groundTransport);
};


#endif //AEDAPROJECT_GROUNDTRANSPORT_H
