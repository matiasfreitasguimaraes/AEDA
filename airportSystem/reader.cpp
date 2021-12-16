//
// Created by jpdat on 16/12/21.
//

#include "reader.h"


set<Plane> Reader::readPlanes(ifstream& planeFile) {
    set<Plane> myPlanes;
    if (planeFile.is_open()) {
        printf("Successfully opened input file!\n");
        int capacity;
        string type;
        string regis;
        Plane key;
        while (!planeFile.eof()) {
            planeFile >> regis >> capacity >> type;
            key = Plane(capacity, type, regis);
            if (myPlanes.find(key) != myPlanes.end()){
                cout << "Plane with " << key.getRegis() << " already exist" << endl;
            }
            else{
                myPlanes.insert(key);
            }
        }
    } else {
        printf("Couldnt read file input.\n");
    }
    return myPlanes;
}

map<string, GroundTransport> Reader::readGroundTransport(ifstream groundFile) {
    map<string, GroundTransport> myTransport;
    if (groundFile.is_open()) {
        printf("Susccefully opened input file!\n");
        string name;
        string type;
        double airDis;
        set<DateTime> sched;
        int hour, min, i;
        while (!groundFile.eof()) {
            getline(groundFile, name);
            groundFile >> type >> airDis >> i;
            for (int j = 0; j < i; ++j) {
                groundFile >> hour >> min;
                sched.insert(DateTime(hour,min));
            }

            if (myTransport.find(name) != myTransport.end()){
                cout <<  name << " transport already exist" << endl;
            }
            else{
                myTransport.emplace(name, GroundTransport(name, type, sched, airDis));
            }
        }
    } else {
        printf("Couldnt read file input.\n");
    }
    return myTransport;
}
