#include "airportSystem/groundTransport.h"


int main() {
    Reader myRead;
    ifstream fileG("ground.txt");
    set<GroundTransport> listGroundTransport = myRead.readGroundTransport(fileG);
    for (GroundTransport ground:listGroundTransport) {
        cout << ground;
    }
}