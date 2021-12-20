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
        case 0:
            return 1;
        case 1:
            do {
            } while (runAdminMenu() == 0);
            break;
        case 2:
            listingMenu();
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
            do {
                option = runPlaneManagerMenu();
            } while (option == 0);
            break;
        case 2:
            do {
                option = runFlightSetManagerMenu();
            } while (option == 0);
            break;
        case 3:
            do {
                option = runAirportManagerMenu();
            } while (option == 0);
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
    option = intInput(0, 4, invalidInput);
    switch (option) {
        case 0:
            return 1;
        case 1:
            airportM.show();
            wait();
            break;
        case 2:
            cout << "What will be its name?\n";
            cin >> input;
            if (airportM.add(Airport(input)) == 1) {
                cout << "Airport added successfully!\n";
            } else {
                cout << "Couldn't add airport... Maybe its name is already being used?\n";
            }
            wait();
            break;
        case 3:
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
        case 4:
            cout << "Which airport's transport services you want to edit?\n";
            cin >> input;
            if (airportM.find(Airport(input))) {
                do {
                    option = runAirportEditingMenu(airportM.get(), input);
                } while ( option == 0);
                break;
            } else {
                cout << "Couldn't find that airport... Maybe you had a typo in the name?\n"
                        "Remember, it's case-sensitive\n";
                wait();
            }
            break;
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
        case 0:
            return 1;
        case 1:
            airport.showGTs();
            wait();
            break;
        case 2:
            cout << "From which transport service you want to operate the schedule?\n";
            cin >> input;
            if (airport.findGT(input)) {
                do {
                    GroundTransport GT = *airport.get().find(GroundTransport(input));
                    option = runScheduleOptionsMenu(GT.getSchedule());
                } while ( option == 0);
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
int Menu::runScheduleOptionsMenu(set<DateTime> &GTDates) {
    DateTime date;
    cout << scheduleOptionsMenu;
    option = intInput(0, 3, invalidInput);
    switch (option) {
        case 1:
            try {
                date = dateInput(false, false, false);
            } catch (inputMinusOne &e) {
                return -1;
            }
            if (GTDates.find(date) != GTDates.end()) {
                cout << "This departure is already scheduled!\n";
            } else {
                GTDates.insert(date);
                cout << "Departure scheduled successfully!\n";
            }
            wait();
            break;
        case 2:
            try {
                date = dateInput(false, false, false);
            } catch (inputMinusOne &e) {
                return -1;
            }
            if(GTDates.find(date) == GTDates.end()) {
                cout << "This departure isn't even scheduled.\n";
            } else {
                GTDates.erase(date);
                cout << "Departure removed from schedule successfully!\n";
            }
            wait();
            break;
        case 3:
            //
            break;
        case 0:
            return 1;
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
            flightToBuyTicketTo = *flightM.get().find(Flight(numberOfFlight));
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

        if (automaticCheckIn) {
            cout << "How many suitcases do you want to be automatic checked in?\n";
            cin >> numberOfSuitcases;

            Luggage passengerLuggage(passenger, automaticCheckIn, numberOfSuitcases);
            if (addLuggageToLuggageCar(passengerLuggage))
                cout << "Automatic check in authorized\n";
            else
                cout << "There are no slots available in any of the luggage cars\n";
        }
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

/**
 * @breif shows ground transports' information per airport
 */
void Menu::groundTransportInformationPerAirport() {
    set<Airport> airports = airportM.get();
    for (Airport airport: airports) {
        airport.showGTs();
    }
}

/**
 * @brief menu providing options for the user to check the flights in a specific order
 */
void Menu::listingMenu() {
    unsigned choice;
    cout << "Choose a listing option:\n";
    cout << "1 - Next flight to departure\n";
    cout << "2 - First flight to arrive to its destination\n";
    cout << "3 - Flight with the highest number of available tickets\n";

    choice = intInput(0, 3, "Invalid option\n");
    auto compare = [](const Flight &f1, const Flight &f2) { return f1.getDepartureDate() < f2.getDepartureDate(); };
    auto compare2 = [](const Flight &f1, const Flight &f2) { return f1.getArrivalDate() < f2.getArrivalDate(); };
    auto compare3 = [](const Flight &f1, const Flight &f2) {
        return f1.getNumberOfTicketsBought() < f2.getNumberOfTicketsBought();
    };
    set<Flight, decltype(compare)> nextFlightToDeparture(compare);
    set<Flight, decltype(compare2)> nextFlightToArrive(compare2);
    set<Flight, decltype(compare3)> flightWithMoreTicketsAvailable(compare3);


    switch (choice) {
        case 1:
            for (Flight flight: flightM.get()) {
                nextFlightToDeparture.insert(flight);
            }
            for (Flight flight: nextFlightToDeparture) {
                cout << flight << endl;
            }
            break;
        case 2:
            for (Flight flight: flightM.get()) {
                nextFlightToArrive.insert(flight);
            }
            for (Flight flight: nextFlightToArrive)
                cout << flight << endl;
            break;
        case 3:
            for (Flight flight: flightM.get()) {
                flightWithMoreTicketsAvailable.insert(flight);
            }
            for (Flight flight: flightWithMoreTicketsAvailable)
                cout << flight << endl;
            break;
        default:
            return;
    }
}

/**
 * @brief date reader
 * @param askYear true if the date contains an year
 * @param askMonth true if the date contains a month
 * @param askDay true if the date contains a day
 * @param askHour true if the date contains an hour
 * @param askMinute true if the date contains a minute
 * @return the read date
 */
DateTime Menu::dateInput(bool askYear, bool askMonth, bool askDay, bool askHour, bool askMinute) {
    int year, month, day, hour, min = 0;
    string invalidHour = "You know we only have 24 hours per day, right?";
    string invalidMinute = "You know an hour only has 60 minutes,  right?";
    string invalidYear = "AEDA Airlines was founded in 2021! We don't register data prior to that!\n"
                         "Nor we do for data regarding dates more than 2 years from now...";
    string invalidMonth = "You know a year only has 12 months, right?";
    string invalidDay = "You know months has 31 days at most, right?";
    if (askYear) {
        cout << "Year:\n";
        year = intInput(2021, 2023, invalidYear);
        if (year == -1)
            throw inputMinusOne();
    }
    if (askMonth) {
        cout << "Month:\n";
        month = intInput(1, 12, invalidMonth);
        if (month == -1)
            throw inputMinusOne();
    }
    if (askDay) {
        cout << "Day:\n";
        day = intInput(1, 31, invalidDay);
        if (day == -1)
            throw inputMinusOne();
    }
    if (askHour) {
        cout << "Hour:\n";
        hour = intInput(0, 24, invalidHour);
        if (hour == -1)
            throw inputMinusOne();
    }
    if (askMinute) {
        cout << "Minute:\n";
        min = intInput(0, 60, invalidMinute);
        if (min == -1)
            throw inputMinusOne();
    }
    return DateTime(year, month, day, hour, min);
}

/**
 * @brief menu dedicated to flight managing
 * @return 0 if running, -1 to come back to the main menu, 1 to exit
 */
int Menu::runFlightSetManagerMenu() {
    DateTime departureDate, arrivalDate;
    string flightCode, origin, destination;
    int temp;
    unsigned int id;
    cout << flightManagerMenu;
    option = intInput(0, 4, invalidInput);
    switch (option) {
        case 1:
            cout << "What will be it's flight code?\n";
            cin >> flightCode;
            if (!flightM.find(Flight(flightCode))) {
                try {
                    cout << "When will be it's departure?\n";
                    departureDate = dateInput();
                    cout << "When will be it's arrival date?\n";
                    arrivalDate = dateInput();
                } catch (inputMinusOne &e) {
                    return -1;
                }
                cout << "Where will it depart from?\n";
                cin >> origin;
                if (origin == "-1")
                    return -1;
                cout << "What's its destination?\n";
                cin >> destination;
                if (destination == "-1")
                    return -1;
                cout << "bota o id ai porra\n";
                temp = intInput(0, 9999, "We only accept positive ID's lower than 9999\n");
                if (temp == -1) {
                    return -1;
                }
                id = temp;
                flightM.add(Flight(flightCode, departureDate, arrivalDate, origin, destination, id));
                cout << "Flight added successfully\n";
                wait();
            } else {
                cout << "There's already a flight with that flight number\n";
                wait();
            }
            break;
        case 2:
            cout << "Select a flight.\n"
                    "Flight code: ";
            cin >> flightCode;
            if (flightM.find(Flight(flightCode))) {
                flightM.remove(Flight(flightCode));
                cout << "Flight removed successfully!";
                wait();
            } else {
                cout << "Sorry but couldn't find a registered flight with that code...";
                wait();
            }
            break;
        case 3:
            listingMenu();
            break;
        case 4:
            cout << "Select a flight.\n"
                    "Flight code: ";
            cin >> flightCode;
            if (flightM.find(Flight(flightCode))) {
                do {
                    option = runFlightObjectManagerMenu(flightM.get(), flightCode);
                } while (option == 0);
            } else {
                cout << "Sorry but couldn't find a registered flight with that code...";
                wait();
            }
            break;
        case 0:
            return 1;
    }
    if (option == -1) {
        return -1;
    }
    return 0;
}

int Menu::runFlightObjectManagerMenu(set<Flight> &flights, string flightCode) {
    set<Flight> uhu = flights;
    string kkk = flightCode;
    return 1;
}

/**
 * @brief menu dedicated to plane managing
 * @return 0 if running, -1 to come back to the main menu, 1 to exit
 */
int Menu::runPlaneManagerMenu() {
    string planeType, planeRegister;
    unsigned planeCapacity, planeId;
    cout << planeManagerMenu;
    option = intInput(0, 4, invalidInput);

    switch (option) {
        case 0:
            return 1;
        case 1:
            cout << "Plane's register:\n";
            cin >> planeRegister;
            cout << "Plane type:\n";
            cin >> planeType;
            cout << "Plane's capacity:\n";
            cin >> planeCapacity;
            cout << "Plane's ID:\n";
            cin >> planeId;

            if (planeM.add(Plane(planeCapacity, planeType, planeRegister, planeId)) == 1) {
                cout << "Plane added successfully\n";
            } else { cout << "Seems like that plane already exists\n";}
            wait();
            break;
        case 2:
            cout << "What's the plane's register you want to remove?\n";
            cin >> planeRegister;

            if (planeM.remove(Plane(planeRegister)) == 1)
                cout << "Plane removed successfully\n";
            else
                cout << "Failed to remove plane. The plane does not exist\n";
            wait();
            break;
        case 3:
            planeM.show();
            break;
        case 4:
            break;
    }
    if (option == -1)
        return -1;
    return 0;
}
