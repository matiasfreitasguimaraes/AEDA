#include "airportSystem/plane.h"
#include "airportSystem/reader.h"


int main() {
    ifstream file("planes.txt");
    Reader myRead;
    set<Plane> listPlanes = myRead.readPlanes(file);
    for (Plane plane:listPlanes) {
        cout << plane;
    }
}
