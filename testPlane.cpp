#include "airportSystem/plane.h"
#include "airportSystem/planeManager.h"


int main() {
    string filename = "planes.txt";
    PlaneManager myRead;
    myRead.readPlanes(filename);

}
