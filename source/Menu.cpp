#include "Menu.h"

Menu::Menu(const string &planeInput, const string &flightInput, const string &luggageCarInput,const string &airportInput )
        : planeFile(planeInput), flightFile(flightInput), luggageCarFile(luggageCarInput), airportFile(airportInput ){
    ifstream planeFileR(planeFile);
    ifstream luggageCarFileR(luggageCarFile);
    ifstream flightFileR(flightFile);
    ifstream airportFileR(airportInput);
    planeM.read(planeFileR);
    flightM.read(flightFileR);
    luggageM.read(luggageCarFileR);
    airportM.read(airportFileR);
    cout << menuTutorial;
}


/**
 * @brief runs the starting menu
 * @return -1 if successfully
 */
int Menu::run() {
    string selectedInput;
    cout << startingMenu;
    option = intInput(0, 4, invalidInput);
    switch (option) {
        case 1:
            do {
            } while (runAdminMenu() == 0);
            break;
        case 2:
            listFlights();
            wait();
            break;
        case 3:
            if (airportM.get().empty()) {
                airportM.show();
                wait();
                return -1;
            }
            cout << "Want me to list the registered airports?\n"
                    "1 - Yes\n"
                    "2 - No\n";
            option = intInput(0, 1, invalidInput);
            if (option == -1) {
                return -1;
            } else if (option == 1) {
                airportM.show();
            } else {}
            cout << "Which airport's transport services you want to check?\n";
            cin >> selectedInput;
            if (selectedInput == "-1") {
                return -1;
            }
            if (airportM.find(Airport(selectedInput))) {
                Airport selectedAirport = *airportM.get().find(Airport(selectedInput));
                selectedAirport.showGTs();
                wait();
                cout << "Want to check the schedule for any of them?\n"
                        "1 - Yes\n"
                        "0 - No\n";
                option = intInput(0, 1, invalidInput);
                if (option == -1) {
                    return -1;
                } else if (option == 1) {
                    cout << "Which one?\n";
                    cin >> selectedInput;
                    if (selectedInput == "-1") {
                        return -1;
                    }
                    selectedAirport.getGT(selectedInput).showSched();
                } else {}
                break;
            } else {
                cout << "Couldn't find that airport... Maybe you had a typo in the name?\n"
                        "Remember, it's case-sensitive\n";
            }
            break;
        case 4:
            buyTicket();
            break;
        case 0:
            return 1;
    }
    return -1;
}

/**
 * @brief runs the menu with the administrator options
 * @return
 */
int Menu::runAdminMenu() {
    cout << adminMenu;
    option = intInput(0, 3, invalidInput);
    switch (option) {
        case 1:
            cout << "yet to implement";
            break;
        case 2:
            cout << "yet to implement";
            break;
        case 3:
            do {
            } while (runAirportManagerMenu() == 0);
            break;
        case 0:
            return 1;
    }
    if (option == -1)
        return -1;
    return 0;
}

/**
 * @brief runs the menu for the management of the airport
 * @return
 */
int Menu::runAirportManagerMenu() {
    string input;
    cout << airportManagerMenu;
    option = intInput(0, 6, invalidInput);
    switch (option) {
        case 1:

            break;
        case 3:
            cout << "What will be its name?\n";
            cin >> input;
            if (airportM.add(Airport(input)) == 1) {
                cout << "Airport added successfully!\n";
            } else {
                cout << "Couldn't add airport... Maybe its name is already being used?\n";
            }
            wait();
            break;
        case 4:
            cout << "What's the name of the airport you want to remove?\n";
            cin >> input;
            if (airportM.remove(Airport(input)) == 1) {
                cout << "Airport removed successfully!\n";
            } else {
                cout << "Couldn't remove airport... Maybe you had a typo in the name?\n"
                        "Remember, it's case-sensitive\n";
            }
            wait();
            break;
        case 6:
            break;
        case 5:
            cout << "Which airport's transport services you want to edit?\n";
            cin >> input;
            if (airportM.find(Airport(input))) {
                do {
                } while (runAirportEditingMenu(airportM.get(), input) == 0);
                break;
            } else {
                cout << "Couldn't find that airport... Maybe you had a typo in the name?\n"
                        "Remember, it's case-sensitive\n";
            }
            break;
        case 2:
            airportM.show();
            wait();
            break;
        case 0:
            return 1;
    }
    if (option == -1)
        return -1;
    return 0;
}

/**
 * @param airports set of airports
 * @param airportName the airport to be edited
 * @return
 */
int Menu::runAirportEditingMenu(set<Airport> &airports, string airportName) {
    Airport airport = *airports.find(Airport(airportName));
    string input, name, type;
    double airDis;
    cout << airportEditingMenu;
    option = intInput(0, 4, invalidInput);
    switch (option) {
        case 1:
            airport.showGTs();
            wait();
            break;
        case 2:
            cout << "From which transport service you want to operate the schedule?\n";
            cin >> input;
            if (airport.findGT(input)) {
                /*
                 * do {
                } while (runScheduleOptionsMenu(airport.getGT(input)) == 0);
                 */
                break;
            } else {
                cout << "Couldn't find a transport service with that name. Maybe you want to check their names?\n"
                        "Remember, they are case-sensitive.\n";
            }
            break;
        case 3:
            cout << "Which will be the transport's station name?\n";
            cin >> name;
            if (airport.findGT(name)) {
                cout << "Ops, seems like that name is already in use!\n";
            } else {
                cout << "And what is its type?\n";
                cin >> type;
                if (type != "Bus" && type != "Subway" && type != "Train") {
                    cout << "That doesn't seem like a valid transport type.\n";
                } else {
                    cout << "And how far is it from the airport? (in meters)\n";
                    airDis = intInput(0, 10000, tooFarAway);
                    airport.addGT(GroundTransport(name, type, airDis));
                    airports.erase(airports.find(Airport(airportName)));
                    airports.insert(airport);
                }
            }
            break;
        case 4:

            break;
        case 0:
            return 1;
    }
    if (option == -1)
        return -1;
    return 0;
}

/**
 * @brief menu to modify schedules
 * @param GTSchedule set of schedules
 * @return
 */
int Menu::runScheduleOptionsMenu(set<GroundTransport> &GTs, string GTName) {
    int hour, minute;
    string input;
    GroundTransport selectedGT = *GTs.find(GroundTransport(GTName));
    cout << scheduleOptionsMenu;
    option = intInput(0, 3, invalidInput);
    switch (option) {
        case 1:
            if (hourInput(hour, minute) == -1) {
                return -1;
            }
            selectedGT.addToSchedule(DateTime(hour, minute));
            GTs.erase(GTs.find(selectedGT));
            GTs.insert(selectedGT);
            break;
        case 2:
            if (hourInput(hour, minute) == -1) {
                return -1;
            }
            selectedGT.removeFromSchedule(DateTime(hour, minute));
            GTs.erase(GTs.find(selectedGT));
            GTs.insert(selectedGT);
            break;
        case 3:
            selectedGT.showSched();
            break;
    }
    if (option == -1)
        return -1;
    return 0;
}

/**
 * @brief checks if the user input is valid
 * @param min minimum integer possible for the input
 * @param max maximum integer possible for the input
 * @return the user's input if valid, -2 otherwise
 */
int Menu::intInput(int min, int max, string errorMessage) {
    string input;
    int output;
    do {
        cin >> input;
        if (input == "-1") {
            return -1;
        }
        try {
            output = stoi(input);
        } catch (invalid_argument &e) {
            cout << errorMessage;
            output = -2;
        }
        if (output < min || output > max) {
            cout << errorMessage;
            output = -2;
        }
    } while (output == -2);
    return output;
}

/**
 * @return the option chosen by the user
 */
int Menu::getOption() const {
    return option;
}

/**
 * @brief changes the option chosen
 * @param opt new option
 */
void Menu::setOption(int opt) {
    this->option = opt;
}

/**
 * @brief waits for the user to press a key
 */
void Menu::wait() {
    cout << "Press any key to continue.\n";
    cin.ignore(99999999,'\n');
    cin.get();
}

/**
 * @brief lists all the flights' information
 */
void Menu::listFlights() {

    flightM.show();
}

/**
 * @brief handles ticket buying as well as automated check ins
 */
void Menu::buyTicket() {
    string name, numberOfFlight, choice;
    unsigned age, ssn, numberOfTickets, numberOfSuitcases;
    bool automaticCheckIn;
    set<Flight> flights = flightM.get();
    set<LuggageCar> luggageCars = luggageM.get();

    cout << "How many tickets do you want to buy?\n";
    cin >> numberOfTickets;
    if(numberOfTickets == 0){
        return;
    }
    cout << "In order to buy a ticket, you must provide some information of the owner\n";

    for (unsigned i = 0; i < numberOfTickets; i++) {
        cout << "Name:\n";
        cin >> name;
        cout << "Age:\n";
        cin >> age;
        cout << "Fiscal Number:\n";
        cin >> ssn;
        Passenger passenger(name, age, ssn);
        cout << "Choose a flight:\n";
        flightM.show();
        cout << "Choose a flight:" << endl;
        cin >> numberOfFlight;

        Flight flightToBuyTicketTo(numberOfFlight);
        try {
            flightToBuyTicketTo = flightM.find(numberOfFlight);
        } catch (bad_alloc &e) { // exception thrown when findFlight doesn't find the flight
            cout << "Flight not found. Please, try again \n";
            break;
        }

        flightToBuyTicketTo.updateBoughtTickets(numberOfTickets);

        if (canBuyTicket(flightToBuyTicketTo)) {
            cout << "Ticket(s) successfully bought\n";
            Ticket(flightToBuyTicketTo, passenger);
        } else {
            cout << "There are not enough available tickets to this flight\n";
            break;
        }

        cout << "Do you want automatic check-in in your luggage? (y/n)\n";
        cin >> choice;
        automaticCheckIn = choice == "y";
        cout << "How many suitcases do you want to be automatic checked in?\n";
        cin >> numberOfSuitcases;

        Luggage passengerLuggage(passenger, automaticCheckIn, numberOfSuitcases);
        if (addLuggageToLuggageCar(passengerLuggage))
            cout << "Automatic check in authorized\n";
        else
            cout << "There are no slots available in any of the luggage cars\n";

    }
}

/**
 * @param flight flight for which ticket is trying to be bought
 * @return true if a passenger can buy the ticket, false otherwise
 */
bool Menu::canBuyTicket(Flight flight) {
    set<Plane> planes = planeM.get();
    for (Plane plane: planes) {
        if (plane.getId() == flight.getFlightId() && flight.getNumberOfTicketsBought() < plane.getCapacity())
            return true;
    }
    return false;
}

/**
 * @brief adds the passengers' luggage to the luggage cars
 * @param luggage the passenger's luggage
 * @return true if any luggage car available in the airport has available slots, false otherwise
 */
bool Menu::addLuggageToLuggageCar(Luggage luggage) {

    set<LuggageCar> luggageCars = luggageM.get();

    for (LuggageCar luggageCar: luggageCars) {
        if (!luggageCar.carIsFull()) {
            luggageCar.addLuggage(luggage);
            return true;
        }
    }
    return false;
}

Menu::~Menu() {
    ofstream flightFileW(flightFile, std::ofstream::out | std::ofstream::trunc);
    ofstream luggageCarFileW(luggageCarFile, std::ofstream::out | std::ofstream::trunc);
    ofstream planeFileW(planeFile, std::ofstream::out | std::ofstream::trunc);
    ofstream airportFileW(airportFile, std::ofstream::out | std::ofstream::trunc);
    planeM.write(planeFileW);
    flightM.write(flightFileW);
    luggageM.write(luggageCarFileW);
    airportM.write(airportFileW);
}

int Menu::hourInput(int &hour, int &minute) {
    string invalidHour = "You know we only have 24 hours per day, right?";
    string invalidMinute = "You know an hour only has 60 minutes,  right?";
    cout << "Hours:\n";
    hour = intInput(0, 24, invalidHour);
    if (hour == -1) {
        return -1;
    }
    cout << "Minutes:\n";
    minute = intInput(0, 60, invalidMinute);
    if (minute == -1) {
        return -1;
    }
    return 1;
}
