#include "../source/objects/plane.h"
#include "../source/manager/planeManager.h"



int main() {
    ifstream fileF("./input/planes.txt");
    PlaneManager myRead;
    myRead.read(fileF);
    myRead.show();
}
