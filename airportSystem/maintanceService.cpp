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

ostream& operator<<(ostream &out, MaintenanceService &maintenanceService) {
    out << maintenanceService.getType() << " service." << std::endl;
    out << "Scheduled for " << maintenanceService.getDate().getDay() << "/" << maintenanceService.getDate().getMonth() << "/" << maintenanceService.getDate().getYear();
    out << " at " << maintenanceService.getDate().getHour() << ":" << maintenanceService.getDate().getMinute() << "." << endl;
    return out;
}