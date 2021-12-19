#include <iostream>

#include "source/Menu.h"

#define PLANEFILE "input/planes.txt"
#define LUGGAGECARFILE "input/luggageCars.txt"
#define FLIGHTFILE "input/flight.txt"
#define AIRPORTFILE "input/airport.txt"

using namespace std;


int main() {
    Menu *menu = new Menu(PLANEFILE,FLIGHTFILE,LUGGAGECARFILE, AIRPORTFILE);
    do {
        menu->setOption(menu->run());
    } while (menu->getOption() == -1);
    delete menu;
    return 0;
}
