#ifndef AEDAPROJECT_PLANE_H
#define AEDAPROJECT_PLANE_H

#include "maintenanceService.h"

#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include "flight.h"

using namespace std;

class Plane{
private:
    unsigned capacity;
    string planeType;
    string regis;
    vector<Flight> listOfFlights;
    static unsigned instances;
    queue<MaintenanceService> pastServices;
    queue<MaintenanceService> scheduledServices;
    unsigned id;
public:
    Plane(){};
    Plane(unsigned &capacity, string &planeType, string &regis, unsigned &Id);
    unsigned getCapacity() const;
    static unsigned getNumberOfInstances();
    string getPlaneType() const;
    string getRegis() const;
    vector<Flight> getListOfFlights() const;
    queue<MaintenanceService> getPastServices() const;
    queue<MaintenanceService> getScheduledServices() const;
    void setListOfFlights(vector<Flight> &flights);
    void addPastService(MaintenanceService &service);
    void addScheduledService(MaintenanceService &scheduledService);
    friend ostream& operator<<(ostream &out,const Plane &plane);

    bool operator<(const Plane &rhs) const;
    bool operator>(const Plane &rhs) const;
    bool operator<=(const Plane &rhs) const;
    bool operator>=(const Plane &rhs) const;
};


#endif //AEDAPROJECT_PLANE_H
