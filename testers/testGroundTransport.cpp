#include "../source/objects/groundTransport.h"
#include "../source/manager/groundTransportManager.h"

int main() {
    GroundTransportManager manageGround;
    ifstream fileG("./input/ground.txt");
    manageGround.read(fileG);
    manageGround.show();
}
