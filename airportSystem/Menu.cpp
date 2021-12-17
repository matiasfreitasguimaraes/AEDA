#include "Menu.h"

Menu::Menu() {}

int Menu::run() {
    int option = -1;
    printf("%s", menuTutorial);
    do {
        printf("%s", startingMenu);
        option = intInput(0, 3);
        switch (option) {
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 0:
                return 0;
        }
    } while (option == -1);
    return 0;
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
        printf("%s", invalidInput);
        return -1;
    }
    if (output < min || output > max) {
        printf("%s", invalidInput);
        return -1;
    }
    return output;
}