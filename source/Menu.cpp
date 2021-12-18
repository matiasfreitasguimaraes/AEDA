#include "Menu.h"

Menu::Menu() {
    cout << menuTutorial;
}

/**
 * @brief runs the starting menu
 * @return
 */
int Menu::run() {
    cout << startingMenu;
    do {
        option = intInput(0, 3);
        switch (option) {
            case 1:
                return runAdminMenu();
            case 2:
                break;
            case 3:
                break;
            case 0:
                return 0;
        }
    } while (option == -2);
    return -1;
}

/**
 * @brief runs the menu with the administrator options
 * @return
 */
int Menu::runAdminMenu() {
    cout << adminMenu;
    do {
        option = intInput(0, 3);
        if (option == -1)
            return -1;
        switch (option) {
            case 1:
                cout << "yet to implement";
                break;
            case 2:
                cout << "yet to implement";
                break;
            case 3:

                break;
            case 0:
                return -1;
        }
    } while (option == -2);
    return -1;
}

/**
 * @brief runs the menu for the management of the airport
 * @return
 */
int Menu::runAirportManagerMenu() {
    airportManager manager = airportManager();
    string input;
    cout << airportManagerMenu;
    do {
        option = intInput(0, 5);
        if (option == -1)
            return -1;
        switch (option) {
            case 1:
                cout << "yet to implement";
                break;
            case 2:
                cout << "What will be it's name?\n";
                cin >> input;
                if (manager.add(Airport(input)) == 1) {
                    cout << "Airport added succesfully!\n";
                } else {
                    cout << "Couldn't add airport... Maybe it's name is already being used?\n";
                }
                option = -2;
                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 0:
                return -1;
        }
    } while (option == -2);
    return -1;
}

/**
 * @param min minimum integer possible for the input
 * @param max maximum integer possible for the input
 * @return
 */
int Menu::intInput(int min, int max) {
    string input;
    int output;
    do {
        cin >> input;
        if (input == "-1") {
            return -1;
        }
        try {
            output = stoi(input);
        } catch (invalid_argument &e) {
            cout << invalidInput;
            output = -2;
        }
        if (output < min || output > max) {
            cout << invalidInput;
            output = -2;
        }
    } while (output == -2);
    return output;
}

/**
 * @return the option chosen by the user
 */
int Menu::getOption() {
    return option;
}

/**
 * @brief changes the option chosen
 * @param opt new option
 */
void Menu::setOption(int opt) {
    this->option = opt;
}

int Menu::tryAgain() {
    cout << "Want to try again?\n"
            "1 - Sure"
            "0 - No";
    return intInput(0, 1);
}