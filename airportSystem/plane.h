#ifndef AEDAPROJECT_PLANE_H
#define AEDAPROJECT_PLANE_H

#include "flight.h"

#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Plane {
private:
    unsigned capacity;
    string planeType;
    string regis;
    vector<Flight> listOfFlights;
    static unsigned instances;
public:
    Plane(unsigned capacity, string planeType, string regis, vector<Flight> flights);
    unsigned getCapacity();
    unsigned getNumberOfInstances();
    string getPlaneType();
    string getRegis();
    vector<Flight> getListOfFlights();
    void setRegis(string newRegister);
    void setListOfFlights(vector<Flight> &flights);
    friend ostream& operator<<(ostream &out, Plane &plane);
};


#endif //AEDAPROJECT_PLANE_H
