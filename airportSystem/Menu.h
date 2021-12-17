#ifndef AEDAPROJECT_MENU_H
#define AEDAPROJECT_MENU_H

#include <iostream>
#include <string>
#include "plane.h"
#include "reader.h"
#include <fstream>
#include <sstream>

using namespace std;

class Menu {
private:
    string userInput;
    const char *const menuTutorial = "Welcome to the AEDA Airport services interface\n"
                                "Navigate through the options by typing the corresponding option code.\n"
                                "You can come back to the starting menu anytime by inputing -1.\n";
    const char *const startingMenu = "Welcome to AEDA Airlines menu.\n"
                                     "1 - Admin options\n"
                                     "2 - Buy Ticket\n"
                                     "3 - Airport transports' information\n"
                                     "0 - Exit\n";
    const char *const adminMenu = "Welcome to the Administrator functions.\n"
                                  "1 - Plane manager\n"
                                  "2 - Flight manager\n"
                                  "3 - Passenger manager\n"
                                  "0 - Return\n";
    constexpr static const char *const invalidInput = "That doesn't seem like a valid input... Care to try again?\n";
public:
    Menu();
    int run();
    int runAdminMenu();
    static int intInput(int min, int max);
};


#endif //AEDAPROJECT_MENU_H
