#include "Menu.h"

Menu::Menu() {
    cout << menuTutorial;
}

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

int Menu::runAirportManagerMenu() {

}

int Menu::intInput(int min, int max) {
    string input;
    int output;
    cin >> input;
    if (input == "-1") {
        return -1;
    }
    try {
        output = stoi(input);
    } catch (invalid_argument &e) {
        cout << invalidInput;
        return -2;
    }
    if (output < min || output > max) {
        cout << invalidInput;
        return -2;
    }
    return output;
}

int Menu::getOption() {
    return option;
}

void Menu::setOption(int opt) {
    this->option = opt;
}