#ifndef AEDAPROJECT_DATA_H
#define AEDAPROJECT_DATA_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class DateTime {
private:
    unsigned int year = 0;
    unsigned int month = 0;
    unsigned int day = 0;
    unsigned int hour = 0;
    unsigned int minute = 0;
public:
    DateTime();
    DateTime(unsigned int h, unsigned int min);
    DateTime(unsigned int y, unsigned int mon, unsigned int d);
    DateTime(unsigned int y, unsigned int mon, unsigned int d, unsigned int h, unsigned int min);

    int getYear();
    int getMonth();
    int getDay();
    int getHour();
    int getMinute();
    friend ostream& operator<<(ostream& out, const DateTime &d1);
    bool operator<(const DateTime &rhs) const;
    bool operator==(const DateTime &rhs) const;
};


#endif //AEDAPROJECT_DATA_H
