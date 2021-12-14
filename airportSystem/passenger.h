#ifndef AEDAPROJECT_PASSENGER_H
#define AEDAPROJECT_PASSENGER_H

#include <string>

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
};


#endif //AEDAPROJECT_PASSENGER_H
