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
    /*a bit about option variable: option is an int which will vary between -2 and the maximum option code.
    the meanings of the -2, -1 and 0 options are:
    -2: invalid input, repeat the method loop until get a valid input
    -1: return to starting menu, the run() method.
     0: the end code, meaning the run method has ended it's job succesfully.
    */
    int option = 0;
    /*
     * tutorial message exhibited only once in program runthrough, namely sent to cout in constructor method.
     */
    const string menuTutorial = "Welcome to the AEDA Airport services interface\n"
                                "Navigate through the options by typing the corresponding option code.\n"
                                "You can come back to the starting menu anytime by inputing -1.\n";
    /*
     * starting menu message and options to be exhibited
     */
    const string startingMenu = "Welcome to AEDA Airlines menu.\n"
                                     "1 - Admin options\n"
                                     "2 - Buy Ticket\n"
                                     "3 - Airport transports' information\n"
                                     "0 - Exit\n";
    /*
     * admin menu message and options to be exhibited
     */
    const string adminMenu = "Welcome to the Administrator functions.\n"
                                  "1 - Plane manager\n"
                                  "2 - Flight manager\n"
                                  "3 - Passenger manager\n"
                                  "4 - Airport manager\n"
                                  "0 - Return\n";
    /*
     * invalid input message to be exhibited
     */
    constexpr static const char* invalidInput = "That doesn't seem like a valid input... Care to try again?\n";
public:
    /*
     * constructor, it only sends tutorial message to cout and instanciates a menu.
     */
    Menu();
    /*
     * getter for option variable
     */
    int getOption();
    /*
     * setter for option variable
     */
    void setOption(int opt);
    /*
     * the starting method of the menu, first run that encapsulates all other menu functionalities.
     */
    int run();
    /*
     * the admin menu method, encapsulated by the general run method, runs through admin functionalities.
     */
    int runAdminMenu();
    /*
     * a tester for valid integer inputs between a minimum and maximum value. Inputing -1 on it will always return -1, due to
     * the return to main menu feature. Made static so it can be used by the manager objects as well.
     */
    static int intInput(int min, int max);
};


#endif //AEDAPROJECT_MENU_H
