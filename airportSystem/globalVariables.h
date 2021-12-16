//
// Created by Matias Freitas Guimarães on 14/12/2021.
//

#ifndef AEDAPROJECT_GLOBALVARIABLES_H
#define AEDAPROJECT_GLOBALVARIABLES_H
#include "dateTime.h"

class GlobalVariables {

private:
    DateTime currentDate;
public:
    GlobalVariables();
    void setCurrentDate(DateTime today);
    DateTime getCurrenDate();

};


#endif //AEDAPROJECT_GLOBALVARIABLES_H
