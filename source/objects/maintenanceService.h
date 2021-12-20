#ifndef AEDAPROJECT_MAINTENANCESERVICE_H
#define AEDAPROJECT_MAINTENANCESERVICE_H

#include "dateTime.h"

#include <string>
#include <iostream>

using namespace std;

class MaintenanceService {
private:
    string type; //Maintenance or Cleaning
    DateTime date;
    string responsible;
    unsigned id;
public:
    // for context with operator << use Bus, Metro or Train for typename.
    MaintenanceService(unsigned serviceId);
    MaintenanceService(unsigned serviceId, string typeName,DateTime when, string employee);
    string getType() const;
    DateTime getDate() const;
    string getResponsible() const;
    unsigned getId() const;
    friend ostream& operator<<(ostream &out, const MaintenanceService &maintenanceService);
    bool operator<(const MaintenanceService &service) const;
    bool operator==(const MaintenanceService &service) const;
};


#endif //AEDAPROJECT_MAINTENANCESERVICE_H
