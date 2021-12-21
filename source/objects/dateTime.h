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
    DateTime(int h, int min);
    DateTime(int y, int mon, int d);
    DateTime(int y, int mon, int d, int h, int min);

    int getYear() const;
    int getMonth() const;
    int getDay() const;
    int getHour() const;
    int getMinute() const;
    friend ostream& operator<<(ostream& out, const DateTime &d1);
    bool operator<(const DateTime &rhs) const;
    bool operator==(const DateTime &rhs) const;
};


#endif //AEDAPROJECT_DATA_H
