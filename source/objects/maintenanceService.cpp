#include "maintenanceService.h"

using namespace std;

MaintenanceService::MaintenanceService(unsigned int serviceId) : id(serviceId) {}

MaintenanceService::MaintenanceService(unsigned serviceId, string typeName, DateTime when, string employee) : type(typeName), date(when), responsible(employee), id(serviceId){}

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
    out << maintenanceService.getId() << " " << maintenanceService.getType() << " " << maintenanceService.getDate() << " " << maintenanceService.getResponsible() << endl;
    return out;
}

/**
 * @param service instance of maintenance service
 * @return the most recent service
 */
bool MaintenanceService::operator<(const MaintenanceService &service) const {
    return date < service.getDate();
}

/**
 * @return the service's ID
 */
unsigned int MaintenanceService::getId() const {
    return id;
}