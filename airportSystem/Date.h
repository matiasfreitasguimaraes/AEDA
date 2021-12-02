//
// Created by Matias Freitas Guimarães on 02/12/2021.
//

#ifndef AEDAPROJECT_DATA_H
#define AEDAPROJECT_DATA_H


class Date {
private:
public:
    Date(unsigned int h, unsigned int min);
    Date(unsigned int y, unsigned int mon, unsigned int d);
    Date(unsigned int y, unsigned int mon, unsigned int d, unsigned int h, unsigned int min);
    const unsigned int year;
    const unsigned int month;
    const unsigned int day;
    const unsigned int hour;
    const unsigned int minute;
    bool operator>(const Date &date);
};


#endif //AEDAPROJECT_DATA_H
