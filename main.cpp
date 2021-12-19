#include <iostream>

#include "source/Menu.h"

using namespace std;


int main() {
    Menu menu = Menu();

    do {
        menu.setOption(menu.run());
    } while (menu.getOption() == -1);

    return 0;
}
