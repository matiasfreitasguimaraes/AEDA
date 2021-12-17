#include "airportSystem/plane.h"
#include "airportSystem/planeManager.h"


int main() {
    ifstream fileF("planes.txt");
    PlaneManager myRead;
    myRead.readPlanes(fileF);
    myRead.showPlanes();

}
