#include "../source/objects/maintenanceService.h"
#include "../source/manager/maintenanceServiceManager.h"

int main() {
    MaintenanceServiceManager manageMaintenance;
    ifstream fileS("./input/maintenance.txt");
    manageMaintenance.read(fileS);
    manageMaintenance.show();
}