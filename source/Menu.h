#ifndef AEDAPROJECT_MENU_H
#define AEDAPROJECT_MENU_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "manager/flightManager.h"
#include "manager/airportManager.h"
#include "manager/planeManager.h"
#include "objects/plane.h"
#include "objects/airport.h"
#include "objects/ticket.h"
#include "manager/luggageCarManager.h"

using namespace std;

class Menu {
private:
    airportManager airportM;
    FlightManager flightM;
    PlaneManager planeM;
    LuggageCarManager luggageM;
    string planeFile;
    string flightFile;
    string luggageCarFile;

    /*  a bit about option variable: option is an int which will vary between -2 and the maximum option code.
    the meanings of the -2, -1 and 0 options are:
    -2: invalid input, repeat the method loop until get a valid input
    -1: return to starting menu, the run() method.
     0: the end code, meaning the run method has ended its job successfully.
    */
    int option = 0;
    /*
     * tutorial message exhibited only once in program run-through, namely sent to cout in constructor method.
     */
    const string menuTutorial = "Welcome to the AEDA Airport services interface\n"
                                "Navigate through the options by typing the corresponding option code.\n"
                                "You can come back to the starting menu anytime by inputting -1.\n";
    /*
     * starting menu message and options to be exhibited
     */
    const string startingMenu = "Welcome to AEDA Airlines menu.\n"
                                     "1 - Admin options\n"
                                     "2 - List flights\n"
                                     "3 - Transports' information by Airport\n"
                                     "4 - Buy tickets\n"
                                     "0 - Exit\n";
    /*
     * admin menu message and options to be exhibited
     */
    const string adminMenu = "Administrator functions:\n"
                                  "1 - Plane manager\n"
                                  "2 - Flight manager\n"
                                  "3 - Airport manager\n"
                                  "0 - Return\n";
    const string airportManagerMenu = "Airport Manager:\n"
                                      "1 - Load airports\n"
                                      "2 - List airports\n"
                                      "3 - Add airport\n"
                                      "4 - Remove airport\n"
                                      "5 - Manage transport services per airport\n"
                                      "6 - Save changes\n"
                                      "0 - Return\n";
    const string airportEditingMenu = "What do you want to do?\n"
                                      "1 - Show nearby transports\n"
                                      "2 - Schedule options per service\n"
                                      "3 - Add a nearby transport\n"
                                      "4 - Remove a nearby transport\n"
                                      "0 - Return\n";
    const string scheduleOptionsMenu = "Schedule options:\n"
                                       "1 - Add scheduled departure\n"
                                       "2 - Remove scheduled departure\n"
                                       "3 - Show scheduled departures\n";
    /*
     * invalid input message to be exhibited
     */
    string tooFarAway = "This seems a little bit too far to be registered in this airport.\n";
    constexpr static const char* invalidInput = "That doesn't seem like a valid input... Care to try again?\n";
public:

    Menu(const string &planeFile, const string &flightFile, const string &luggageFile);

    ~Menu();

    int getOption() const;
    void setOption(int opt);
    void listFlights();
    void buyTicket();
    int run();
    int runAdminMenu();
    int runAirportManagerMenu();
    int runScheduleOptionsMenu(set<DateTime> &GTSchedule);
    int runAirportEditingMenu(set<Airport> &airports, string airportName);
    static int intInput(int min, int max, string errorMessage);
    void wait();
    bool canBuyTicket(Flight flight);
    bool addLuggageToLuggageCar(Luggage luggage);
};


#endif //AEDAPROJECT_MENU_H
