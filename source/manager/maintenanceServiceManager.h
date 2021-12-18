#ifndef AEDAPROJECT_MAINTENANCESERVICEMANAGER_H
#define AEDAPROJECT_MAINTENANCESERVICEMANAGER_H

#include "../objects/maintenanceService.h"

#include <set>
#include <fstream>

class MaintenanceServiceManager {
private:
    set<MaintenanceService> maintenanceServices;
public:
    void read(ifstream &file);
    void add(MaintenanceService service);
    void remove(MaintenanceService serviceToRemove);
    void write(ofstream &file);
    void show();
};


#endif //AEDAPROJECT_MAINTENANCESERVICEMANAGER_H
