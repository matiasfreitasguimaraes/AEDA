//
// Created by Matias Freitas Guimarães on 02/12/2021.
//

#include "date.h"

Date::Date(unsigned int h, unsigned int min) : year(0), month(0), day(0), hour(h), minute(min){}

Date::Date(unsigned int y, unsigned int mon, unsigned int d) : year(y), month(mon), day(d), hour(0), minute(0) {}

Date::Date(unsigned int y, unsigned int mon, unsigned int d, unsigned int h, unsigned int min) : year(y), month(mon), day(d), hour(h), minute(min) {}

int Date::getYear(){
    return this->year;
}

int Date::getMonth(){
    return this->month;
}

int Date::getDay(){
    return this->day;
}

int Date::getHour(){
    return this->hour;
}

int Date::getMinute(){
    return this->minute;
}

bool operator>(Date dateMax, Date dateMin) {
    if (dateMax.getYear() > dateMin.getYear()){
        return true;
    }else if(dateMax.getYear() != dateMin.getYear()){
        return false;
    }
    if (dateMax.getMonth() > dateMin.getMonth()){
        return true;
    }else if(dateMax.getMonth() != dateMin.getMonth()){
        return false;
    }
    if (dateMax.getDay() > dateMin.getDay()){
        return true;
    }else if(dateMax.getDay() != dateMin.getDay()){
        return false;
    }
    if (dateMax.getHour() > dateMin.getHour()){
        return true;
    }else if(dateMax.getHour() != dateMin.getHour()){
        return false;
    }
    if (dateMax.getMinute() > dateMin.getMinute()){
        return true;
    }else{
        return false;
    }
}

bool operator<(Date dateMin, Date dateMax) {
    return !(dateMin > dateMax || dateMin==dateMax);
}


bool operator==(Date dateL, Date dateR) {
    return (dateL.getYear() == dateR.getYear()
            && dateL.getMonth() == dateR.getMonth()
            && dateL.getDay() == dateR.getDay()
            && dateL.getHour() == dateR.getHour()
            && dateL.getMinute() == dateR.getMinute());
}
