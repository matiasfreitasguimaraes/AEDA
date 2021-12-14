//
// Created by Matias Freitas Guimarães on 02/12/2021.
//

#ifndef AEDAPROJECT_DATA_H
#define AEDAPROJECT_DATA_H


class Date {
private:
    unsigned int year;
    unsigned int month;
    unsigned int day;
    unsigned int hour;
    unsigned int minute;
public:
    Date(unsigned int h, unsigned int min);
    Date(unsigned int y, unsigned int mon, unsigned int d);
    Date(unsigned int y, unsigned int mon, unsigned int d, unsigned int h, unsigned int min);
    int getYear();
    int getMonth();
    int getDay();
    int getHour();
    int getMinute();
};

bool operator==(Date dateL, Date dateR);
bool operator>(Date dateMin, Date dateMax);
bool operator<(Date dateMax, Date dateMin);
#endif //AEDAPROJECT_DATA_H
