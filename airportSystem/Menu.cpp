#include "Menu.h"

Menu::Menu() {}

int Menu::run() {
    return 0;
}

int Menu::checkInput(string input) {
    try {
        stoi(input);
    } catch (invalid_argument &e) {
        cerr << "Invalid argument " << e.what() << endl;
        return -1;
    }
    return 0;
}