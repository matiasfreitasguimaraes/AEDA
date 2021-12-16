#include "dateTime.h"

DateTime::DateTime(unsigned int h, unsigned int min) : year(0), month(0), day(0), hour(h), minute(min){}

DateTime::DateTime(unsigned int y, unsigned int mon, unsigned int d) : year(y), month(mon), day(d), hour(0), minute(0) {}

DateTime::DateTime(unsigned int y, unsigned int mon, unsigned int d, unsigned int h, unsigned int min) : year(y), month(mon), day(d), hour(h), minute(min) {}

/**
 * @return the date's year
 */
int DateTime::getYear(){
    return this->year;
}

/**
 * @return the date's month
 */
int DateTime::getMonth(){
    return this->month;
}

/**
 * @return the date's day
 */
int DateTime::getDay(){
    return this->day;
}

/**
 * @return the date's hour
 */
int DateTime::getHour(){
    return this->hour;
}

/**
 * @return the date's minute
 */
int DateTime::getMinute(){
    return this->minute;
}

/**
 * @param dateMax date instance
 * @param dateMin date instance
 * @return the most recente date
 */
bool operator>(DateTime dateMax, DateTime dateMin) {
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

/**
 * @param dateMin date instance
 * @param dateMax date instance
 * @return the oldest date
 */
bool operator<(DateTime dateMin, DateTime dateMax) {
    return !(dateMin > dateMax || dateMin==dateMax);
}

/**
 * @param dateL date instance
 * @param dateR date instance
 * @return true if two dates are equal, false otherwise
 */
bool operator==(DateTime dateL, DateTime dateR) {
    return (dateL.getYear() == dateR.getYear()
            && dateL.getMonth() == dateR.getMonth()
            && dateL.getDay() == dateR.getDay()
            && dateL.getHour() == dateR.getHour()
            && dateL.getMinute() == dateR.getMinute());
}

/**
 * @param out output stream
 * @param d1 date instance
 * @return all the date information
 */
ostream& operator<<(ostream &out, const DateTime &d1) {
    out << d1.day << "/" << d1.month << "/" << d1.year << " " << d1.hour << ":" << d1.minute;
    return out;
}
