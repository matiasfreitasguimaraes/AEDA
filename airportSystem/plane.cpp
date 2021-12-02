
#include "plane.h"

/**
 * @param capacity the plane's capacity
 * @param planeType the plane type
 * @param regis the plane's register
 * @param flights the plane's list of flights
 */
Plane::Plane(unsigned planeCapacity, string type, string planeRegister, vector<Flight> flights) : capacity(planeCapacity), planeType(type), listOfFlights(flights) {
    this->regis = planeRegister;
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
unsigned int Plane::getNumberOfInstances() const {
    return instances;
}

/**
 * @param newRegister the plane's new register
 */
void Plane::setRegis(string newRegister) {
    this->regis = newRegister;
}

/**
 * @param flights the plane's new list of flights
 */
void Plane::setListOfFlights(vector<Flight> &flights) {
    this->listOfFlights = flights;
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
    for (unsigned i = 0; i < plane.getListOfFlights().size(); i++) {
        out << "Flight " << i << ": " <<  plane.getListOfFlights().at(i) << endl;
    }
    return out;
}

unsigned Plane::instances = 0;