#ifndef AEDAPROJECT_LUGGAGECARMANAGER_H
#define AEDAPROJECT_LUGGAGECARMANAGER_H

#include "../objects/luggageCar.h"

#include <set>
#include <fstream>

class LuggageCarManager {
private:
    set<LuggageCar> luggageCars;
public:
    void read(ifstream &file);
    void add(LuggageCar luggageCar);
    void remove(LuggageCar luggageCarToRemove);
    void write(ofstream &file);
    void show();
    set<LuggageCar> getLuggageCars();
};


#endif //AEDAPROJECT_LUGGAGECARMANAGER_H
