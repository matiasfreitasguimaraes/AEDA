#include "maintenanceService.h"

using namespace std;

MaintenanceService::MaintenanceService(const string typeName, const DateTime when, const string employee) : type(typeName), date(when), responsible(employee) {}

/**
 * @return the type of maintenance service
 */
string MaintenanceService::getType() const {
    return type;
}

/**
 * @return the date of maintenance service
 */
DateTime MaintenanceService::getDate() const {
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
ostream& operator<<(ostream &out, const MaintenanceService &maintenanceService) {
    out << "Maintenance type: " << maintenanceService.getType() << endl;
    out << "Date: " << maintenanceService.getDate() << endl;
    out << "Responsible employee: " << maintenanceService.getResponsible() << endl;
    return out;
}

/**
 * @param service instance of maintenance service
 * @return the most recent service
 */
bool MaintenanceService::operator<(const MaintenanceService &service) const {
    return date < service.getDate();
}
