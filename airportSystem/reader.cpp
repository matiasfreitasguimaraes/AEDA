#include "reader.h"

set<Plane> Reader::readPlanes(string &filename) {
    ifstream planeFile(filename);
    set<Plane> myPlanes;
    unsigned capacity, id = 1;

    if (planeFile.is_open()) {
        cout << "Successfully opened input file!" << endl;
        string type, regis;

        while (!planeFile.eof()) {
            planeFile >> regis >> capacity >> type;
            Plane key(capacity, type, regis, id);

            if (myPlanes.find(key) != myPlanes.end()){
                cout << "Plane with " << key.getRegis() << " already exist" << endl;
            }
            else{
                myPlanes.insert(key);
                id++;
            }
        }
    } else { cout << "Couldn't read file input." << endl; }
    return myPlanes;
}

/*
map<string, GroundTransport> Reader::readGroundTransport(ifstream groundFile) {
    map<string, GroundTransport> myTransport;
    if (groundFile.is_open()) {
        printf("Successfully opened input file!\n");
        string name;
        string type;
        double airDis;
        set<DateTime> sched;
        unsigned hour, min, i;

        while (!groundFile.eof()) {
            getline(groundFile, name);
            groundFile >> type >> airDis >> i;
            for (unsigned j = 0; j < i; ++j) {
                groundFile >> hour >> min;
                DateTime date(hour, min);
                sched.insert(date);
            }

            if (myTransport.find(name) != myTransport.end()){ //TODO fix this if statement, name does not exist anymore
                cout <<  name << " transport already exist" << endl;
            }
            else{
                myTransport.emplace(name, GroundTransport(type, sched, airDis));
            }
        }
    } else {
        printf("Couldn't read file input.\n");
    }
    return myTransport;
}*/
