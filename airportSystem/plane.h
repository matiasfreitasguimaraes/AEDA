//
// Created by Matias Freitas Guimarães on 29/11/2021.
//

#ifndef AEDAPROJECT_PLANE_H
#define AEDAPROJECT_PLANE_H
#include <string>
#include "flight.h"


class plane {
    private:
        const unsigned int capacity;
        const std::string planeType;
        std::string regis;
        flight* listOfFlights;
    public:
        int getCapacity();
        std::string getPlaneType();
        std::string getRegis();
        flight getListOfFlights();
        void setRegis();
        void setListOfFlights();
};

plane.capacity = 10;
#endif //AEDAPROJECT_PLANE_H
