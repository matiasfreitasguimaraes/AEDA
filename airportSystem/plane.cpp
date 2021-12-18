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
void Plane::addScheduledService(MaintenanceService &scheduledService) {
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

unsigned Plane::instances = 0;

/**
 * @brief updates the list of flights of a plane
 * @param flights the new list of flights
 */
void Plane::setListOfFlights(vector<Flight> flights) {
    this->listOfFlights = flights;
}

bool Plane::operator<(const Plane &rhs) const {
    return regis < rhs.regis;
}

bool Plane::operator>(const Plane &rhs) const {
    return rhs < *this;
}

bool Plane::operator<=(const Plane &rhs) const {
    return !(rhs < *this);
}

bool Plane::operator>=(const Plane &rhs) const {
    return !(*this < rhs);
}

/**
 * @return the plane's id
 */
unsigned int Plane::getId() const {
    return id;
}

