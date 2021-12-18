#ifndef AEDAPROJECT_MENU_H
#define AEDAPROJECT_MENU_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "manager/flightManager.h"
#include "manager/airportManager.h"
#include "objects/plane.h"
#include "objects/airport.h"

using namespace std;

class Menu {
private:
    /*  a bit about option variable: option is an int which will vary between -2 and the maximum option code.
    the meanings of the -2, -1 and 0 options are:
    -2: invalid input, repeat the method loop until get a valid input
    -1: return to starting menu, the run() method.
     0: the end code, meaning the run method has ended its job successfully.
    */
    int option = 0;
    vector<Airport> airports;
    /*
     * tutorial message exhibited only once in program run-through, namely sent to cout in constructor method.
     */
    const string menuTutorial = "Welcome to the AEDA Airport services interface\n"
                                "Navigate through the options by typing the corresponding option code.\n"
                                "You can come back to the starting menu anytime by inputting -1.\n";
    /*
     * starting menu message and options to be exhibited
     */
    const string startingMenu = "Welcome to AEDA Airlines menu.\n"
                                     "1 - Admin options\n"
                                     "2 - List flights\n"
                                     "3 - Transports' information by Airport\n"
                                     "0 - Exit\n";
    /*
     * admin menu message and options to be exhibited
     */
    const string adminMenu = "Administrator functions:\n"
                                  "1 - Plane manager\n"
                                  "2 - Flight manager\n"
                                  "3 - Airport manager\n"
                                  "0 - Return\n";
    const string airportManagerMenu = "Airport Manager:\n"
                                      "1 - Load airports\n"
                                      "2 - Add airport\n"
                                      "3 - Remove airport\n"
                                      "4 - Edit airport\n"
                                      "5 - Save changes\n"
                                      "0 - Return\n";
    /*
     * invalid input message to be exhibited
     */
    constexpr static const char* invalidInput = "That doesn't seem like a valid input... Care to try again?\n";
public:
    Menu();
    int getOption();
    void setOption(int opt);
    int run();
    int runAdminMenu();
    int runAirportManagerMenu();
    static int intInput(int min, int max);
};


#endif //AEDAPROJECT_MENU_H
