#ifndef AEDAPROJECT_DATA_H
#define AEDAPROJECT_DATA_H

#include <iostream>
#include <string>

using namespace std;

class DateTime {
private:
    unsigned int year;
    unsigned int month;
    unsigned int day;
    unsigned int hour;
    unsigned int minute;
public:
    DateTime(unsigned int h, unsigned int min);
    DateTime(unsigned int y, unsigned int mon, unsigned int d);
    DateTime(unsigned int y, unsigned int mon, unsigned int d, unsigned int h, unsigned int min);
    int getYear();
    int getMonth();
    int getDay();
    int getHour();
    int getMinute();
    friend ostream& operator<<(ostream& out, const DateTime &d1);
};

bool operator==(DateTime dateL, DateTime dateR);
bool operator>(DateTime dateMin, DateTime dateMax);
bool operator<(DateTime dateMax, DateTime dateMin);

#endif //AEDAPROJECT_DATA_H
