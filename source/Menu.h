#ifndef AEDAPROJECT_MENU_H
#define AEDAPROJECT_MENU_H

#include "manager/flightManager.h"
#include "manager/airportManager.h"
#include "manager/planeManager.h"
#include "objects/plane.h"
#include "objects/airport.h"
#include "objects/ticket.h"
#include "manager/luggageCarManager.h"

class inputMinusOne {
public:
    inputMinusOne() {};
};

class Menu {
private:
    AirportManager airportM;
    FlightManager flightM;
    PlaneManager planeM;
    LuggageCarManager luggageM;
    string planeFile;
    string flightFile;
    string luggageCarFile;
    string airportFile;

    /* a bit about option variable: option is an int which will vary between -2 and the maximum option code.
    the meanings of the -2, -1 and 0 options are:
    -2: invalid input, repeat the method loop until get a valid input
    -1: return to starting menu, the run() method.
     0: the end code, meaning the run method has ended its job successfully.
    */
    int option = 0;

    // tutorial message exhibited only once in program run-through, namely sent to cout in constructor method.
    const string menuTutorial = "Welcome to the AED Airport services interface\n"
                                "Navigate through the options by typing the corresponding option code.\n"
                                "You can come back to the starting menu anytime by inputting -1.\n";

    // starting menu message and options to be exhibited
    const string startingMenu = "Welcome to AED Airlines menu.\n"
                                     "1 - Admin options\n"
                                     "2 - List flights\n"
                                     "3 - Transports' information by Airport\n"
                                     "4 - Buy tickets\n"
                                     "0 - Exit\n";

    // admin menu message and options to be exhibited
    const string adminMenu = "Administrator functions:\n"
                                  "1 - Plane manager\n"
                                  "2 - Flight manager\n"
                                  "3 - Airport manager\n"
                                  "0 - Return\n";

    // airport managing menu message and options
    const string airportManagerMenu = "Airport Manager:\n"
                                      "1 - List airports\n"
                                      "2 - Add airport\n"
                                      "3 - Remove airport\n"
                                      "4 - Manage transport services per airport\n"
                                      "0 - Return\n";

    // airport editing menu message and options
    const string airportEditingMenu = "What do you want to do?\n"
                                      "1 - Show nearby transports\n"
                                      "2 - Schedule options per service\n"
                                      "3 - Add a nearby transport\n"
                                      "4 - Remove a nearby transport\n"
                                      "0 - Return\n";
    // schedule options
    const string scheduleOptionsMenu = "Schedule options:\n"
                                       "1 - Add scheduled departure\n"
                                       "2 - Remove scheduled departure\n"
                                       "3 - Show scheduled departures\n"
                                       "0 - Return\n";

    // flight managing menu message and options
    const string flightManagerMenu = "Flight management options:\n"
                                    "1 - Add flight\n"
                                    "2 - Remove flight\n"
                                    "3 - List flights\n"
                                    "0 - Return\n";

    // plane managing menu message and options
    const string planeManagerMenu = "Plane management options:\n"
                                    "1 - Add plane\n"
                                    "2 - Remove plane\n"
                                    "3 - List planes\n"
                                    "4 - Manage a plane\n"
                                    "0 - Return\n";

    // plane editing menu message and options
    const string planeEditingMenu = "Plane options\n"
                                    "1 - Add a maintenance service\n"
                                    "2 - Remove a maintenance service\n"
                                    "3 - List maintenance services\n"
                                    "4 - Mark a service as completed\n";

     //invalid input messages to be exhibited
    const string tooFarAway = "This seems a little bit too far to be registered in this airport.\n";
    const string invalidInput = "That doesn't seem like a valid input... Care to try again?\n";

public:
    Menu(const string &planeInput, const string &flightInput,
         const string &luggageCarInput, const string &airportInput);
    ~Menu();
    int getOption() const;
    void setOption(int opt);
    void buyTicket();
    int run();
    int runAdminMenu();
    int runAirportManagerMenu();
    int runAirportEditingMenu(set<Airport> &airports, const string airportName);
    int runScheduleOptionsMenu(set<Airport> &managerAirports, string airportName, string GTName);
    static int intInput(int min, int max, string errorMessage);
    void wait();
    bool canBuyTicket(Flight flight);
    bool addLuggageToLuggageCar(Luggage luggage);
    void listingMenu();
    DateTime dateInput(bool askYear = true, bool askMonth = true, bool askDay = true, bool askHour = true, bool askMinute = true);
    int runFlightSetManagerMenu();
    int runPlaneManagerMenu();
    int runPlaneEditingMenu();
    void assignFlightsToPlanes();
};


#endif //AEDAPROJECT_MENU_H
