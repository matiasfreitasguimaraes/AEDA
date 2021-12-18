#include "airportSystem/plane.h"



int main() {
    ifstream fileF("planes.txt");
    PlaneManager myRead;
    myRead.readPlanes(fileF);
    myRead.showPlanes();


}
