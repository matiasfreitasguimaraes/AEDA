#ifndef AEDAPROJECT_PASSENGER_H
#define AEDAPROJECT_PASSENGER_H

#include <string>
#include <iostream>

using namespace std;

class Passenger {
private:
    string name;
    unsigned age;
    unsigned ssn;
public:
    string getName() const;
    unsigned getAge() const;
    unsigned getSsn() const;
    friend ostream& operator<<(ostream &out, const Passenger &p1);
};


#endif //AEDAPROJECT_PASSENGER_H
