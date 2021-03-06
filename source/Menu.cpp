#include "Menu.h"

Menu::Menu(const string &planeInput, const string &flightInput, const string &luggageCarInput, const string &airportInput)
        : planeFile(planeInput), flightFile(flightInput), luggageCarFile(luggageCarInput), airportFile(airportInput ){
    ifstream planeFileR(planeFile);
    ifstream luggageCarFileR(luggageCarFile);
    ifstream flightFileR(flightFile);
    ifstream airportFileR(airportInput);
    planeM.read(planeFileR);
    flightM.read(flightFileR);
    luggageM.read(luggageCarFileR);
    airportM.read(airportFileR);
    assignFlightsToPlanes();
    cout << menuTutorial;
}


/**
 * @brief runs the starting menu
 * @return 0 if successfully, -1 to come back to the main menu, 1 to exit
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
                option = runAdminMenu();
            } while (option == 0);
            break;
        case 2:
            listingMenu();
            break;
        case 3:
            if (airportM.get().empty()) {
                airportM.show();
                return -1;
            }
            cout << "Do you want to check the existing airports?\n"
                    "1 - Yes\n"
                    "2 - No\n";
            option = intInput(0, 1, invalidInput);

            if (option == -1)
                return -1;
            else if (option == 1)
                airportM.show();

            cout << "Which airport's transport services you want to check? (Enter airport's name)\n";
            cin >> selectedInput;

            if (selectedInput == "-1")
                return -1;

            if (airportM.find(Airport(selectedInput))) {
                Airport selectedAirport = *airportM.get().find(Airport(selectedInput));
                selectedAirport.showGTs();

                cout << "Do you want to check the schedule for any of them?\n"
                        "1 - Yes\n"
                        "0 - No\n";
                option = intInput(0, 1, invalidInput);

                if (option == -1)
                    return -1;
                else if (option == 1) {
                    cout << "Which one? (Transport name)\n";
                    cin >> selectedInput;
                    if (selectedInput == "-1")
                        return -1;

                    selectedAirport.getGT(selectedInput).showSched();
                }
                break;
            } else
                cout << "Couldn't find that airport... Maybe you had a typo in the name?\n"
                        "Remember, it's case-sensitive\n";
            break;
        case 4:
            buyTicket();
            break;
    }
    return -1;
}

/**
 * @brief runs the menu with the administrator options
 * @return 0 if successfully, -1 to come back to the main menu, 1 to exit
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
 * @return 0 if successfully, -1 to come back to the main menu, 1 to exit
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
            cout << "Which airport's transport services you want to edit? (Airport name)\n";
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
 * @return 0 if successfully, -1 to come back to the main menu, 1 to exit
 */
int Menu::runAirportEditingMenu(set<Airport> &airports, string airportName) {
    string input, name, type;
    double airDis;
    Airport airport = *airports.find(Airport(airportName));
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
            cout << "From which transport service you want to operate the schedule? (Enter the transport's name)\n";
            cin >> input;
            if (airport.findGT(input)) {
                do {
                    option = runScheduleOptionsMenu(airports, airportName, input);
                } while ( option == 0);
                break;
            } else {
                cout << "Couldn't find a transport service with that name. Maybe you want to check their names?\n"
                        "Remember, they are case-sensitive.\n";
                wait();
            }
            break;
        case 3:
            cout << "Which will be the transport's station name?\n";
            cin >> name;
            if (airport.findGT(name)) {
                cout << "Ops, seems like that name is already in use!\n";
                wait();
            } else {
                cout << "And what is its type?\n";
                cin >> type;
                if (type != "Bus" && type != "Subway" && type != "Train") {
                    cout << "That doesn't seem like a valid transport type.\n";
                    wait();
                } else {
                    cout << "And how far is it from the airport? (in meters)\n";
                    airDis = intInput(0, 10000, tooFarAway);
                    airport.addGT(GroundTransport(name, type, airDis));
                    airports.erase(airports.find(Airport(airportName)));
                    airports.insert(airport);
                    cout << "Station added successfully!\n";
                    wait();
                }
            }
            break;
        case 4:
            cout << "What's the transport's name you want to remove?\n";
            cin >> name;
            if (airport.findGT(name)) {
                airport.removeGT(GroundTransport(name));
                airports.erase(airports.find(Airport(airportName)));
                airports.insert(airport);
                cout << "Transport station removed successfully!\n";
            } else {
                cout << "There is no transport station with that name registered.\n";
            }
            wait();
            break;
    }
    if (option == -1)
        return -1;
    return 0;
}

/**
 * @brief menu to modify schedules
 * @param GTSchedule set of schedules
 * @return 0 if successfully, -1 to come back to the main menu, 1 to exit
 */
int Menu::runScheduleOptionsMenu(set<Airport> &managerAirports, string airportName, string GTName) {

    Airport updatedAirport = *managerAirports.find(Airport(airportName));
    set<GroundTransport>& airpGTs = updatedAirport.get();
    GroundTransport updatedGT = *airpGTs.find(GroundTransport(GTName));
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
            if (updatedGT.findInSchedule(date)) {
                cout << "This departure is already scheduled!\n";
            } else {
                updatedGT.addToSchedule(date);
                airpGTs.erase(airpGTs.find(updatedGT));
                airpGTs.insert(updatedGT);
                managerAirports.erase(managerAirports.find(updatedAirport));
                managerAirports.insert(updatedAirport);
                cout << "Departure scheduled successfully!\n";
            }
            break;
        case 2:
            try {
                date = dateInput(false, false, false);
            } catch (inputMinusOne &e) {
                return -1;
            }
            if (updatedGT.findInSchedule(date)) {
                updatedGT.removeFromSchedule(date);
                airpGTs.erase(airpGTs.find(updatedGT));
                airpGTs.insert(updatedGT);
                managerAirports.erase(managerAirports.find(updatedAirport));
                managerAirports.insert(updatedAirport);
                cout << "Departure removed from schedule successfully!\n";
            } else {
                cout << "This departure isn't even scheduled.\n";
            }
            break;
        case 3:
            updatedGT.showSched();
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
 * @brief checks if the user input is valid
 * @param min minimum integer possible for the input
 * @param max maximum integer possible for the input
 * @param errorMessage message to display if the input is invalid
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
    cin.ignore(9999999999999,'\n');
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
    if(numberOfTickets == 0)
        return;

    cout << "In order to buy a ticket, you must provide some information\n";

    for (unsigned i = 0; i < numberOfTickets; i++) {
        cout << "Name:\n";
        cin >> name;
        cout << "Age:\n";
        cin >> age;
        cout << "SSN:\n";
        cin >> ssn;
        Passenger passenger(name, age, ssn);
        listingMenu();
        cout << "Choose a flight: (Number of flight)" << endl;
        cin >> numberOfFlight;

        Flight flightToBuyTicketTo(numberOfFlight);

        if(flightM.get().find(Flight(numberOfFlight)) == flightM.get().end()) {
            cout << "Flight not found. Please, try again \n";
            break;
        }
        flightToBuyTicketTo = *flightM.get().find(flightToBuyTicketTo);
        flightToBuyTicketTo.updateBoughtTickets(numberOfTickets);

        if (canBuyTicket(flightToBuyTicketTo)) {
            cout << "Ticket(s) successfully bought\n";
            Ticket(flightToBuyTicketTo, passenger);
        } else {
            cout << "There are not enough available tickets to this flight\n";
            wait();
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
        wait();
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
 * @brief menu providing options for the user to check the flights in a specific order
 */
void Menu::listingMenu() {

    cout << "Choose a listing option:\n";
    cout << "1 - Next flight to departure\n";
    cout << "2 - First flight to arrive to its destination\n";
    cout << "3 - Flight with the highest number of available tickets\n";

    option = intInput(0, 3, invalidInput);

    auto compare = [](const Flight &f1, const Flight &f2) { return f1.getDepartureDate() < f2.getDepartureDate(); };
    auto compare2 = [](const Flight &f1, const Flight &f2) { return f1.getArrivalDate() < f2.getArrivalDate(); };
    auto compare3 = [](const Flight &f1, const Flight &f2) { return f1.getNumberOfTicketsBought() < f2.getNumberOfTicketsBought(); };

    set<Flight, decltype(compare)> nextFlightToDeparture(compare);
    set<Flight, decltype(compare2)> nextFlightToArrive(compare2);
    set<Flight, decltype(compare3)> flightWithMoreTicketsAvailable(compare3);


    switch (option) {
        case 1:
            for (Flight flight: flightM.get())
                nextFlightToDeparture.insert(flight);

            for (Flight flight: nextFlightToDeparture)
                cout << flight << endl;
            break;
        case 2:
            for (Flight flight: flightM.get())
                nextFlightToArrive.insert(flight);

            for (Flight flight: nextFlightToArrive)
                cout << flight << endl;
            break;
        case 3:
            for (Flight flight: flightM.get())
                flightWithMoreTicketsAvailable.insert(flight);

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
    string invalidYear = "AED Airlines was founded in 2021! We don't register data prior to that!\n"
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
    int tempID;
    unsigned id;
    cout << flightManagerMenu;

    option = intInput(0, 3, invalidInput);

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

                cout << "What's its ID?\n";
                tempID = intInput(0, 9999, invalidInput);

                if (tempID == -1) {
                    return -1;
                }
                id = tempID;
                flightM.add(Flight(flightCode, departureDate, arrivalDate, origin, destination, id));
                cout << "Flight added successfully\n";
            } else
                cout << "There's already a flight with that flight number\n";

            break;
        case 2:
            cout << "Flight code to remove:\n";
            cin >> flightCode;

            if (flightM.find(Flight(flightCode))) {
                flightM.remove(Flight(flightCode));
                cout << "Flight removed successfully!\n";
            } else
                cout << "Sorry but couldn't find a registered flight with that code...\n";

            break;
        case 3:
            listingMenu();
            break;
        case 0:
            return 1;
    }
    if (option == -1) {
        return -1;
    }
    return 0;
}

/**
 * @brief menu dedicated to plane managing
 * @return 0 if successfully, -1 to come back to the main menu, 1 to exit
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
            } else
                cout << "Seems like that plane already exists\n";

            break;
        case 2:
            cout << "What's the plane you want to remove? (Plane register)\n";
            cin >> planeRegister;

            for(Plane plane: planeM.get()) {
                auto helper = flightM.get();

                for(Flight flight: helper) {
                    if (plane.getId() == flight.getFlightId() && plane == Plane(planeRegister))
                        flightM.remove(flight);
                }
            }
            if (planeM.remove(Plane(planeRegister)) == 1)
                cout << "Plane removed successfully\n";
            else
                cout << "Failed to remove plane. The plane does not exist\n";

            break;
        case 3:
            planeM.show();
            break;
        case 4:
            runPlaneEditingMenu();
            break;
    }
    wait();
    if (option == -1)
        return -1;
    return 0;
}

/**
 * @brief runs the managing of a plane menu
 * @return 0 if successfully, -1 to come back to the main menu, 1 to exit
 */
int Menu::runPlaneEditingMenu() {
    string planeRegister, serviceType, responsible, service;
    unsigned serviceId;
    cout << "Choose a plane: (Plane register)\n";
    cin >> planeRegister;
    Plane planeToEdit(planeRegister);

    if (planeM.find(planeToEdit)) {
        planeToEdit = *planeM.get().find(planeToEdit);
        auto scheduledServices = planeToEdit.getScheduledServices();
        auto pastServices = planeToEdit.getPastServices();
        cout << planeEditingMenu;
        option = intInput(0, 4, invalidInput);

        switch (option) {
            case 0:
                return 1;
            case 1:
                cout << "Service ID:\n";
                cin >> serviceId;
                cout << "What is the type of service? (Maintenance/Cleaning)\n";
                cin >> serviceType;
                cout << "Who is responsible for the service?\n";
                cin >> responsible;
                cout << "When is it scheduled?\n";
                planeToEdit.addScheduledService(MaintenanceService(serviceId, serviceType, dateInput(1,1,1,1,1), responsible));
                planeM.remove(Plane(planeRegister));
                planeM.add(planeToEdit);
                cout << "Service added successfully\n";
                break;
            case 2:
                cout << "Service ID:\n";
                cin >> serviceId;

                if (planeToEdit.removeScheduledService(MaintenanceService(serviceId))) {
                    planeM.remove(Plane(planeRegister));
                    planeM.add(planeToEdit);
                    cout << "Service removed successfully\n";
                } else
                    cout << "Seems like there is not a service with that ID\n";

                break;
            case 3:
                cout << "Past services\n";

                while(!pastServices.empty()) {
                    cout << pastServices.front();
                    pastServices.pop();
                }
                cout << "Scheduled services\n";

                while(!scheduledServices.empty()) {
                    cout << scheduledServices.front();
                    scheduledServices.pop();
                }
                break;
            case 4:
                cout << "What service do you want to mark as completed? (Service ID)\n";
                cin >> serviceId;

                if (planeToEdit.markServiceAsCompleted(MaintenanceService(serviceId))) {
                    planeM.remove(Plane(planeRegister));
                    planeM.add(planeToEdit);
                    cout << "Service marked as completed successfully\n";
                } else
                    cout << "Seems like there is not a service with that ID\n";
                break;
        }
    } else
        cout << "Seems like that plane doesn't exist\n";

    if(option == -1)
        return -1;
    return 0;
}

/**
 * @brief assigns flights to planes. If a flight has the same ID as a plane, than that flight belongs to that plane
 */
void Menu::assignFlightsToPlanes() {
    vector<Flight> temp;
    set<Plane> helper;

    for(Plane plane: planeM.get()) {
        for(const Flight &flight: flightM.get()) {
            if(flight.getFlightId() == plane.getId())
                plane.addFlight(flight);
        }
        helper.insert(plane);
    }
    planeM.setPlanes(helper);
}
