#include "passenger.h"

using namespace std;

Passenger::Passenger(string passengerName, unsigned passengerAge, unsigned passengerSsn) {
    this->name = passengerName;
    this->age = passengerAge;
    this->ssn = passengerSsn;
}

/**
 * @return the passenger's age
 */
unsigned int Passenger::getAge() const {
    return age;
}

/**
 * @return the passenger's name
 */
string Passenger::getName() const {
    return name;
}

/**
 * @return the passenger's ssn
 */
unsigned int Passenger::getSsn() const {
    return ssn;
}

/**
 * @param out output stream
 * @param p1 instance of Passenger
 * @return all the information related to a passenger
 */
ostream& operator<<(ostream &out, const Passenger &p1) {
    out << "Passenger information: " << endl;
    out << "Name: " << p1.getName() << endl;
    out << "Age: " << p1.getAge() << endl;
    out << "SSN: " << p1.getSsn() << endl;
    return out;
}
