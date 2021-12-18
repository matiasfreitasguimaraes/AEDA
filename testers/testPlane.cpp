#include "airportSystem/plane.h"
#include


int main() {
    ifstream fileF("planes.txt");
    PlaneManager myRead;
    myRead.readPlanes(fileF);
    myRead.showPlanes();

}
