#ifndef AEDAPROJECT_PLANE_H
#define AEDAPROJECT_PLANE_H

#include "flight.h"

#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Plane {
private:
    const unsigned capacity;
    const string planeType;
    string regis;
    vector<Flight> listOfFlights;
    static unsigned instances;
public:
    Plane(unsigned capacity, string planeType, string regis, vector<Flight> flights);
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
