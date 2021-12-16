#include "maintenanceService.h"

using namespace std;

MaintenanceService::MaintenanceService(const string typeName, const Date when, const string employee) : type(typeName), date(when), responsible(employee) {}

/**
 * @return the type of maintenance service
 */
string MaintenanceService::getType() const {
    return type;
}

/**
 * @return the date of maintenance service
 */
Date MaintenanceService::getDate() const {
    return date;
}

/**
 * @return the person responsible for the maintenance service
 */
string MaintenanceService::getResponsible() const {
    return responsible;
}

/**
 * @param out output stream
 * @param maintenanceService instance of maintenanceService
 * @return all the information related to the service
 */
ostream& operator<<(ostream &out, MaintenanceService &maintenanceService) {
    out << maintenanceService.getType() << " service." << std::endl;
    out << "Scheduled for " << maintenanceService.getDate().getDay() << "/" << maintenanceService.getDate().getMonth() << "/" << maintenanceService.getDate().getYear();
    out << " at " << maintenanceService.getDate().getHour() << ":" << maintenanceService.getDate().getMinute() << "." << endl;
    return out;
}