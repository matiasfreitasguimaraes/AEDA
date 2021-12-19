#include "passenger.h"

using namespace std;

Passenger::Passenger(string passengerName, unsigned passengerAge, unsigned passengerSsn) {
    this->name = passengerName;
    this->age = passengerAge;
    this->ssn = passengerSsn;
}

unsigned int Passenger::getAge() const {
    return age;
}

string Passenger::getName() const {
    return name;
}

unsigned int Passenger::getSsn() const {
    return ssn;
}

ostream& operator<<(ostream &out, const Passenger &p1) {
    out << "Passenger information: " << endl;
    out << "Name: " << p1.getName() << endl;
    out << "Age: " << p1.getAge() << endl;
    out << "SSN: " << p1.getSsn() << endl;
    return out;
}