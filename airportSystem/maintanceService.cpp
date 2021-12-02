#include "maintanceService.h"

using namespace std;

string MaintenanceService::getType() const {
    return type;
}
tm MaintenanceService::getDate() const {
    return date;
}
string MaintenanceService::getResponsible() const {
    return responsible;
}

ostream& operator<<(ostream &out, const MaintenanceService &maintenanceService) {
    tm date = maintenanceService.getDate();
    out << maintenanceService.getType() << " service." << std::endl;
    out << "Realized day " << date.tm_mday << "/" << date.tm_mon << "/" << date.tm_year % 100;
    out << " at " << date.tm_hour << ":" << date.tm_min << "." << endl;
    return out;
}