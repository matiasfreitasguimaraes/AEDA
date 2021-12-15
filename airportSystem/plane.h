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
    queue<MaintenanceService> pastServices;
    queue<MaintenanceService> scheduledServices;
public:
    Plane();
    Plane(unsigned capacity, string planeType, string regis);
    unsigned getCapacity() const;
    unsigned getNumberOfInstances() const;
    string getPlaneType() const;
    string getRegis() const;
    vector<Flight> getListOfFlights() const;
    queue<MaintenanceService> getPastServices() const;
    queue<MaintenanceService> getScheduledServices() const;
    void setRegis(string newRegister);
    void setListOfFlights(vector<Flight> &flights);
    void addPastService(MaintenanceService &service);
    void addScheduledService(MaintenanceService &scheduledService);
    friend ostream& operator<<(ostream &out, const Plane &plane);
};


#endif //AEDAPROJECT_PLANE_H
