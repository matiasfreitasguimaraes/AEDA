#ifndef AEDAPROJECT_MAINTENANCESERVICE_H
#define AEDAPROJECT_MAINTENANCESERVICE_H

#include "dateTime.h"

#include <string>
#include <iostream>

using namespace std;

class MaintenanceService {
private:
    string type;
    DateTime date;
    string responsible;
public:
    // for context with operator << use bus, metro or train for typename.
    MaintenanceService(string typeName,DateTime when, string employee);
    string getType() const;
    DateTime getDate() const;
    string getResponsible() const;
    friend ostream& operator<<(ostream &out, const MaintenanceService &maintenanceService);
    bool operator<(const MaintenanceService &service) const;
};


#endif //AEDAPROJECT_MAINTENANCESERVICE_H
