#include "plane.h"
#include "flight.h"

/**
 * @param capacity the plane's capacity
 * @param planeType the plane type
 * @param regis the plane's register
 * @param flights the plane's list of flights
 */
Plane::Plane(unsigned planeCapacity, string type, string planeRegister, unsigned Id) : capacity(planeCapacity),
        planeType(type), regis(planeRegister), id(Id){

    instances++;
}

Plane::Plane(unsigned int planeId) {
    this->id=planeId;
}

/**
 * @param planeRegister the plane's register
 */
Plane::Plane(string planeRegister) {
    this->regis = planeRegister;
}

unsigned Plane::instances = 0;

/**
 * @return the plane's capacity
 */
unsigned Plane::getCapacity() const {
    return capacity;
}

/**
 * @return the plane type
 */
string Plane::getPlaneType() const {
    return planeType;
}

/**
 * @return the plane's register
 */
string Plane::getRegis() const {
    return regis;
}

/**
 * @return the plane's list of flights
 */
vector<Flight> Plane::getListOfFlights() const {
    return listOfFlights;
}

/**
 * @return the numbers of existing planes
 */
unsigned int Plane::getNumberOfInstances() {
    return instances;
}

/**
 * @param out output stream
 * @param plane instance of Plane
 * @return all the plane information
 */
ostream& operator<<(ostream &out, const Plane &plane) {
    out << "Plane's capacity: " << plane.getCapacity() << endl;
    out << "Plane's register: " << plane.getRegis() << endl;
    out << "Plane type: " << plane.getPlaneType() << endl;
    out << "Plane's list of flights:" << endl;
    for(Flight flight: plane.getListOfFlights())
        out << flight << endl;
    return out;
}

/**
 * @brief adds service to the past services queue
 * @param service instance of MaintenanceService
 */
void Plane::addPastService(MaintenanceService &service) {
    pastServices.push(service);
}

/**
 * @brief adds service to the scheduled services
 * @param scheduledService instance of MaintenanceService
 */
void Plane::addScheduledService(MaintenanceService scheduledService) {
    scheduledServices.push(scheduledService);
}

/**
 * @return queue with the past services
 */
queue<MaintenanceService> Plane::getPastServices() const {
    return pastServices;
}

/**
 * @return queue with the scheduled services
 */
queue<MaintenanceService> Plane::getScheduledServices() const {
    return scheduledServices;
}

/**
 * @brief sets the list of flights of a plane
 * @param flights the new list of flights
 */
void Plane::addFlight(Flight flight) {
    listOfFlights.push_back(flight);
}

/**
 * @param rhs instance of plane
 * @return the plane with lower register
 */
bool Plane::operator<(const Plane &rhs) const {
    return regis < rhs.regis;
}

/**
 * @return the plane's ID
 */
unsigned int Plane::getId() const {
    return id;
}

/**
 * @param rhs instance of Plane
 * @return true if two planes have the same register
 */
bool Plane::operator==(const Plane &rhs) const {
    return regis == rhs.regis;
}

/**
 * @brief removes a scheduled service
 * @param serviceToRemove service to be removed
 */
bool Plane::removeScheduledService(MaintenanceService serviceToRemove) {
    queue<MaintenanceService> helper;
    queue<MaintenanceService> comparisonQueue = scheduledServices;
    while(!scheduledServices.empty()) {
        if (scheduledServices.front().getId() == serviceToRemove.getId()) {
            scheduledServices.pop();
        } else {
            helper.push(scheduledServices.front());
            scheduledServices.pop();
        }
    }
    if (helper == comparisonQueue) { // service not found
        scheduledServices = comparisonQueue;
        return false;
    } else {
        scheduledServices = helper;
        return true;
    }
}

bool Plane::markServiceAsCompleted(MaintenanceService serviceToBeCompleted) {
    queue<MaintenanceService> helper;
    queue<MaintenanceService> comparisonQueue = scheduledServices;
    while(!scheduledServices.empty()) {
        if(scheduledServices.front().getId() == serviceToBeCompleted.getId()) {
            pastServices.push(scheduledServices.front());
            scheduledServices.pop();
        } else {
            helper.push(scheduledServices.front());
            scheduledServices.pop();
        }
    }
    if (helper == comparisonQueue) { // service not found
        scheduledServices = comparisonQueue;
        return false;
    } else {
        scheduledServices = helper;
        return true;
    }
}
