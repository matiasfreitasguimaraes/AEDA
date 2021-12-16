#ifndef AEDAPROJECT_GLOBALVARIABLES_H
#define AEDAPROJECT_GLOBALVARIABLES_H

#include "dateTime.h"

class GlobalVariables {

private:
    DateTime currentDate;
public:
    GlobalVariables();
    void setCurrentDate(DateTime today);
    DateTime getCurrentDate();
};


#endif //AEDAPROJECT_GLOBALVARIABLES_H
