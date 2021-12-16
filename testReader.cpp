#include "airportSystem/plane.h"
#include "airportSystem/reader.h"


int main() {
    string filename = "planes.txt";
    Reader myRead;
    set<Plane> listPlanes = myRead.readPlanes(filename);
    for (Plane plane:listPlanes) {
        cout << plane;
    }
}
