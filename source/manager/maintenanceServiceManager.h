#ifndef AEDAPROJECT_MAINTENANCESERVICEMANAGER_H
#define AEDAPROJECT_MAINTENANCESERVICEMANAGER_H

#include "../objects/maintenanceService.h"

#include <set>
#include <fstream>

class MaintenanceServiceManager {
private:
    set<MaintenanceService> maintenanceServices;
public:
    ///Writer and reader functions
        ///to files
    void read(ifstream &file);
    void write(ostream &file);
        ///to console
    void show();

    ///update and delete
    void add(MaintenanceService service);
    void remove(MaintenanceService serviceToRemove);
};


#endif //AEDAPROJECT_MAINTENANCESERVICEMANAGER_H
