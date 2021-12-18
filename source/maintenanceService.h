#ifndef AEDAPROJECT_MAINTENANCESERVICE_H
#define AEDAPROJECT_MAINTENANCESERVICE_H

#include "dateTime.h"
#include <string>
#include <iostream>

using namespace std;

/*
 * i'm opting here for creating the attributes as constants thinking about how an object of this
 * class will keep data from things that has already happened, because we can't, for example, change
 * the responsible for a completed service.
 */
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
};


#endif //AEDAPROJECT_MAINTENANCESERVICE_H
