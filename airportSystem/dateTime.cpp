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
 * @param out output stream
 * @param d1 date instance
 * @return all the date information
 */
ostream& operator<<(ostream &out, const DateTime &d1) {
    out << d1.day << "/" << d1.month << "/" << d1.year << " " << d1.hour << ":" << d1.minute;
    return out;
}

bool DateTime::operator<(const DateTime &rhs) const {
    if (year < rhs.year)
        return true;
    if (rhs.year < year)
        return false;
    if (month < rhs.month)
        return true;
    if (rhs.month < month)
        return false;
    if (day < rhs.day)
        return true;
    if (rhs.day < day)
        return false;
    if (hour < rhs.hour)
        return true;
    if (rhs.hour < hour)
        return false;
    return minute < rhs.minute;
}

bool DateTime::operator>(const DateTime &rhs) const {
    return rhs < *this;
}

bool DateTime::operator<=(const DateTime &rhs) const {
    return !(rhs < *this);
}

bool DateTime::operator>=(const DateTime &rhs) const {
    return !(*this < rhs);
}

DateTime::DateTime() {}

bool DateTime::operator==(const DateTime &rhs) const {
    return year == rhs.year &&
           month == rhs.month &&
           day == rhs.day &&
           hour == rhs.hour &&
           minute == rhs.minute;
}

bool DateTime::operator!=(const DateTime &rhs) const {
    return !(rhs == *this);
}
