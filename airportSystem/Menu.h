//
// Created by jpdat on 05/12/21.
//

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
    const string menuTutorial = "Navigate through the options by typing the corresponding option code. "
                                "You can come back to the starting menu anytime by inputing -1.";
    const string startingMenu = "Welcome to AEDA Airlines menu.\n"
                                "1 - Plane manager\n";
public:
    Menu();
    int run();
    static int checkInput(string input);
};


#endif //AEDAPROJECT_MENU_H
