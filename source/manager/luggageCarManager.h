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
    void write(ostream &file);
    void add(LuggageCar luggageCar);
    void remove(LuggageCar luggageCarToRemove);
    set<LuggageCar> get();
    void show();
};


#endif //AEDAPROJECT_LUGGAGECARMANAGER_H
