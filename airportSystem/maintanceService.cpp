#include "maintanceService.h"

using namespace std;

MaintenanceService::MaintenanceService(const string typeName, const Date when, const string employee) : type(typeName), date(when), responsible(employee) {}

string MaintenanceService::getType() const {
    return type;
}
Date MaintenanceService::getDate() const {
    return date;
}
string MaintenanceService::getResponsible() const {
    return responsible;
}

ostream& operator<<(ostream &out, const MaintenanceService &maintenanceService) {
    out << maintenanceService.getType() << " service." << std::endl;
    out << "Scheduled for " << maintenanceService.date.day << "/" << maintenanceService.date.month << "/" << maintenanceService.date.year;
    out << " at " << maintenanceService.date.hour << ":" << maintenanceService.date.minute << "." << endl;
    return out;
}