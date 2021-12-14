#ifndef AEDAPROJECT_MAINTANCESERVICE_H
#define AEDAPROJECT_MAINTANCESERVICE_H

#include "date.h"
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
    const string type;
    const Date date;
    const string responsible;
public:
    // for context with operator << use bus, metro or train for typename.
    MaintenanceService(string typeName, Date when, string employee);
    string getType() const;
    Date getDate() const;
    string getResponsible() const;
    friend ostream& operator<<(ostream &out, const MaintenanceService &maintenanceService);
};


#endif //AEDAPROJECT_MAINTANCESERVICE_H
