#include "dateTime.h"

DateTime::DateTime() {}

DateTime::DateTime(int h, int min) : year(0), month(0), day(0), hour(h), minute(min){}

DateTime::DateTime(int y, int mon, int d) : year(y), month(mon), day(d), hour(0), minute(0) {}

DateTime::DateTime(int y, int mon, int d, int h, int min) : year(y), month(mon), day(d), hour(h), minute(min) {}

/**
 * @return the date's year
 */
int DateTime::getYear() const {
    return year;
}

/**
 * @return the date's month
 */
int DateTime::getMonth() const {
    return month;
}

/**
 * @return the date's day
 */
int DateTime::getDay() const {
    return day;
}

/**
 * @return the date's hour
 */
int DateTime::getHour() const {
    return hour;
}

/**
 * @return the date's minute
 */
int DateTime::getMinute() const {
    return minute;
}

/**
 * @param out output stream
 * @param d1 DateTime instance
 * @return all the date information
 */
ostream& operator<<(ostream &out, const DateTime &d1) {
    out << std::setfill('0') << std::setw(2) << d1.day
        << "/" << std::setfill('0') << std::setw(2) << d1.month
        << "/"<< d1.year
        << " " << std::setfill('0') << std::setw(2) << d1.hour
        << ":" << std::setfill('0') << std::setw(2) << d1.minute;
    return out;
}

/**
 * @param rhs instance of DateTime
 * @return the oldest date
 */
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

/**
 * @param rhs instance of DateTime
 * @return true if two dates are equal
 */
bool DateTime::operator==(const DateTime &rhs) const {
    return year == rhs.year &&
           month == rhs.month &&
           day == rhs.day &&
           hour == rhs.hour &&
           minute == rhs.minute;
}
