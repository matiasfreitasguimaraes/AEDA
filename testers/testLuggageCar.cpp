#include "../source/objects/ticket.h"
#include "../source/manager/ticketManager.h"


int main() {
    LuggageCarManager manageLuggageCar;
    ifstream fileT("./input/luggageCar.txt");
    manageLuggageCar.read(fileT);
    manageLuggageCar.show();
}
