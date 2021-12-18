#include "menu.h"

menu::menu() {
    cout << menuTutorial;
}

/**
 * @brief runs the starting menu
 * @return
 */
int menu::run() {
    cout << startingMenu;
    option = intInput(0, 3);
    switch (option) {
        case 1:
            do {
            } while (runAdminMenu() == 0);
            break;
        case 2:
            break;
        case 3:
            break;
        case 0:
            return 1;
    }
    return -1;
}

/**
 * @brief runs the menu with the administrator options
 * @return
 */
int menu::runAdminMenu() {
    cout << adminMenu;
    option = intInput(0, 3);
    switch (option) {
        case 1:
            cout << "yet to implement";
            break;
        case 2:
            cout << "yet to implement";
            break;
        case 3:
            do {
            } while (runAirportManagerMenu() == 0);
            break;
        case 0:
            return 1;
    }
    if (option == -1)
        return -1;
    return 0;
}

/**
 * @brief runs the menu for the management of the airport
 * @return
 */
int menu::runAirportManagerMenu() {
    string input;
    cout << airportManagerMenu;
    option = intInput(0, 5);
    switch (option) {
        case 1:
            cout << "yet to implement";
            break;
        case 3:
            cout << "What will be it's name?\n";
            cin >> input;
            if (airportM.add(Airport(input)) == 1) {
                cout << "Airport added succesfully!\n";
            } else {
                cout << "Couldn't add airport... Maybe it's name is already being used?\n";
            }
            wait();
            break;
        case 4:
            cout << "What's the name of the airport you want to remove?\n";
            cin >> input;
            if (airportM.remove(Airport(input)) == 1) {
                cout << "Airport removed succesfully!\n";
            } else {
                cout << "Couldn't remove airport... Maybe you had a typo in the name?\n"
                        "Remember, it's case-sensitive\n";
            }
            wait();
            break;
        case 6:

            break;
        case 5:
            cout << "Which airport's transport services you want to edit?";
            cin >> input;
            if (airportM.findAirport(Airport(input))) {

            } else {
                cout << "Couldn't find that airport... Maybe you had a typo in the name?\n"
                        "Remember, it's case-sensitive\n";
            }
            break;
        case 2:
            airportM.listAirports();
            wait();
            break;
        case 0:
            return 1;
    }
    if (option == -1)
        return -1;
    return 0;
}

int menu::runAirportEditingMenu(Airport airport) {
    string input;
    cout << airportEditingMenu;
    option = intInput(0, 3);
    switch (option) {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 0:

            break;
    }
    if (option == -1)
        return -1;
    return 0;
}

/**
 * @param min minimum integer possible for the input
 * @param max maximum integer possible for the input
 * @return
 */
int menu::intInput(int min, int max) {
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
            output = 0;
        }
    } while (output == -2);
    return output;
}

/**
 * @return the option chosen by the user
 */
int menu::getOption() {
    return option;
}

/**
 * @brief changes the option chosen
 * @param opt new option
 */
void menu::setOption(int opt) {
    this->option = opt;
}

void menu::wait() {
    cout << "Press any key to continue.\n";
    cin. ignore(99999999,'\n');
    cin.get();
}
