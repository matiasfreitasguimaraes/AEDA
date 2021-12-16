#include "airportSystem/groundTransport.h"
#include "airportSystem/dateTime.h"


int main() {
    set<DateTime> mySchedule;
    mySchedule.insert(DateTime(2021,12,16,13,30));
    mySchedule.insert(DateTime(2021,12,16,13,0));
    mySchedule.insert(DateTime(2021,12,16,12,20));
    GroundTransport train("train", "train", mySchedule, 20);
    set<DateTime> mySchedule;
    mySchedule.insert(DateTime(2021,12,16,13,30));
    mySchedule.insert(DateTime(2021,12,16,13,0));
    mySchedule.insert(DateTime(2021,12,16,12,20));
    GroundTransport train("train", "train", mySchedule, 20);
    set<DateTime> mySchedule;
    mySchedule.insert(DateTime(2021,12,16,13,30));
    mySchedule.insert(DateTime(2021,12,16,13,0));
    mySchedule.insert(DateTime(2021,12,16,12,20));
    GroundTransport train("subway", "subway", mySchedule, 8);
    mySchedule.insert(DateTime(2021,12,16,13,30));
    mySchedule.insert(DateTime(2021,12,16,13,0));
    mySchedule.insert(DateTime(2021,12,16,12,20));
    GroundTransport train("taxi", "taxi", mySchedule, 0);
}
