#include "../source/objects/ticket.h"
#include "../source/manager/luggageCarManager.h"

#include <fstream>

int main() {
    LuggageCarManager manageLuggageCar;
    ifstream fileT("./input/luggageCar.txt");
    manageLuggageCar.read(fileT);
    manageLuggageCar.show();
}
