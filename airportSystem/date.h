//
// Created by Matias Freitas Guimarães on 02/12/2021.
//

#ifndef AEDAPROJECT_DATA_H
#define AEDAPROJECT_DATA_H


class date {
private:
public:
    date(unsigned int h, unsigned int min);
    date(unsigned int y, unsigned int mon, unsigned int d);
    date(unsigned int y, unsigned int mon, unsigned int d, unsigned int h, unsigned int min);
    const unsigned int year;
    const unsigned int month;
    const unsigned int day;
    const unsigned int hour;
    const unsigned int minute;
    bool operator>(const date &date);
};


#endif //AEDAPROJECT_DATA_H
