#ifndef AEDAPROJECT_PLANE_H
#define AEDAPROJECT_PLANE_H

#include "maintenanceService.h"

#include <string>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

class Flight;

class Plane {
private:
    unsigned capacity;
    string planeType;
    string regis;
    vector<Flight> listOfFlights;
    static unsigned instances;
    vector<MaintenanceService> serviceRegister;
    queue<MaintenanceService> serviceQueue;
public:
    Plane();
    Plane(unsigned capacity, string planeType, string regis);
    unsigned getCapacity() const;
    unsigned getNumberOfInstances() const;
    string getPlaneType() const;
    string getRegis() const;
    vector<Flight> getListOfFlights() const;
    void setRegis(string newRegister);
    void setListOfFlights(vector<Flight> &flights);
    friend ostream& operator<<(ostream &out, const Plane &plane);
};


#endif //AEDAPROJECT_PLANE_H
