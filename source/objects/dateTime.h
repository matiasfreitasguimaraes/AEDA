#ifndef AEDAPROJECT_DATA_H
#define AEDAPROJECT_DATA_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class DateTime {
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
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
