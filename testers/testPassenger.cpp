#include "../source/objects/passenger.h"
#include "../source/manager/passengerManager.h"


int main() {
    PassengerManager managePassenger;
    ifstream fileP("./input/passenger.txt");
    managePassenger.read(fileP);
    managePassenger.show();
}