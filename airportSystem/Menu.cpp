//
// Created by jpdat on 05/12/21.
//

#include "Menu.h"

Menu::Menu() {}

int Menu::run() {
    return 0;
}

int Menu::checkInput(string input) {
    int check;
    try {
        check = stoi(input);
    } catch (invalid_argument) {
        return 1;
    }
    if (check == -1)
        return -1;
    return 0;
}