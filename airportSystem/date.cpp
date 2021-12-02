//
// Created by Matias Freitas Guimarães on 02/12/2021.
//

#include "date.h"

date::date(unsigned int h, unsigned int min) : year(0), month(0), day(0), hour(h), minute(min){

}

date::date(unsigned int y, unsigned int mon, unsigned int d) : year(y), month(mon), day(d), hour(0), minute(0){
}


date::date(unsigned int y, unsigned int mon, unsigned int d, unsigned int h, unsigned int min) : year(y), month(mon), day(d), hour(h), minute(min){
}


bool date::operator>(const date &date) {
    if (this->year > date.year){
        return true;
    }else if(this->year != date.year){
        return false;
    }
    if (this->month > date.month){
        return true;
    }else if(this->month != date.month){
        return false;
    }
    if (this->day > date.day){
        return true;
    }else if(this->day != date.day){
        return false;
    }
    if (this->hour > date.hour){
        return true;
    }else if(this->hour != date.hour){
        return false;
    }
    if (this->minute > date.minute){
        return true;
    }else{
        return false;
    }
}


