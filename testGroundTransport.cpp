#include "airportSystem/groundTransport.h"
#include "airportSystem/dateTime.h"


int main() {
    set<DateTime> mySchedule;
    mySchedule.insert(DateTime(2021,12,16,13,30));
    mySchedule.insert(DateTime(2021,12,16,13,0));
    mySchedule.insert(DateTime(2021,12,16,12,20));
    GroundTransport train("Train", mySchedule, 10);
    cout << train;
    train.addToSchedule(DateTime(2021,12,16,12,00));
    train.addToSchedule(DateTime(2021,12,16,12,20));
    cout << train;
    train.removeFromSchedule(DateTime(2021,12,16,12,20));
    cout << train;
}
