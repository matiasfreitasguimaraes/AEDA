#include "../source/objects/plane.h"
#include "../source/manager/planeManager.h"

int main() {
    ifstream fileP("./input/planes.txt");
    PlaneManager managePlane;
    managePlane.read(fileP);
    managePlane.show();
}
