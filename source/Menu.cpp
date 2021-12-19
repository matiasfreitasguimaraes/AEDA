#include "Menu.h"

Menu::Menu() {
    cout << menuTutorial;
}

/**
 * @brief runs the starting menu
 * @return
 */
int Menu::run() {
    cout << startingMenu;
    option = intInput(0, 4, invalidInput);
    switch (option) {
        case 1:
            do {
            } while (runAdminMenu() == 0);
            break;
        case 2:
            listFlights();
            break;
        case 3:
            // mostrar informaçoes dos transportes por aeroporto
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
    option = intInput(0, 5, invalidInput);
    switch (option) {
        case 1:
            cout << "yet to implement";
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
            if (airportM.findAirport(Airport(input))) {
                do {
                } while (runAirportEditingMenu(airportM.getAirports(), input) == 0);
                break;
            } else {
                cout << "Couldn't find that airport... Maybe you had a typo in the name?\n"
                        "Remember, it's case-sensitive\n";
            }
            break;
        case 2:
            airportM.listAirports();
            wait();
            break;
        case 0:
            return 1;
    }
    if (option == -1)
        return -1;
    return 0;
}

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

int Menu::runScheduleOptionsMenu(set<DateTime> &GTSchedule) {
    string input;
    cout << scheduleOptionsMenu;
    option = intInput(0, 3, std::string());
    switch (option) {
        case 1:
            int hour, minute;
            cout << "At what time is the new departure scheduled for?\n"
                    "Hours: ";
            hour = intInput(0, 24, std::string());
            cout << "Minutes: ";
            minute = intInput(0, 60, std::string());
            if (hour == -1 || minute == -1)
                option = -1;
            GTSchedule.insert(DateTime(hour, minute));
            break;
        case 2:

            break;
        case 3:

            break;
    }
    if (option == -1)
        return -1;
    return 0;
}

/**
 * @param min minimum integer possible for the input
 * @param max maximum integer possible for the input
 * @return
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
            output = 0;
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

void Menu::wait() {
    cout << "Press any key to continue.\n";
    cin.ignore(99999999,'\n');
    cin.get();
}

void Menu::listFlights() {
    ifstream flightFile("input/flight.txt");
    flightM.read(flightFile);
    flightM.show();
}

void Menu::buyTicket() {
    ifstream flightFile("input/flight.txt");
    flightM.read(flightFile);
    string name, numberOfFlight, choice;
    unsigned age, ssn, numberOfTickets, numberOfSuitcases;
    bool automaticCheckIn;
    set<Flight> flights = flightM.getFlights();
    set<LuggageCar> luggageCars = luggageM.getLuggageCars();

    cout << "How many tickets do you want to buy?\n";
    cin >> numberOfTickets;
    cout << "In order to buy a ticket, you must provide some information of the owner\n";

    for (unsigned i = 0; i < numberOfTickets; i++) {
        cout << "Name:\n";
        cin >> name;
        cout << "Age:\n";
        cin >> age;
        cout << "SSN:\n";
        cin >> ssn;
        Passenger passenger(name, age, ssn);
        cout << "Number of flight:\n";
        cin >> numberOfFlight;

        Flight flightToBuyTicketTo(numberOfFlight);
        try {
            flightToBuyTicketTo = flightM.findFlight(numberOfFlight);
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

bool Menu::canBuyTicket(Flight flight) {
    ifstream planeFile("input/planes.txt");
    planeM.read(planeFile);
    set<Plane> planes = planeM.getPlanes();
    for (Plane plane: planes) {
        if (plane.getId() == flight.getFlightId() && flight.getNumberOfTicketsBought() < plane.getCapacity())
            return true;
    }
    return false;
}

bool Menu::addLuggageToLuggageCar(Luggage luggage) {
    ifstream luggageCarFile("input/luggageCars.txt");
    luggageM.read(luggageCarFile);
    set<LuggageCar> luggageCars = luggageM.getLuggageCars();

    for (LuggageCar luggageCar: luggageCars) {
        if (!luggageCar.carIsFull()) {
            luggageCar.addLuggage(luggage);
            return true;
        }
    }
    return false;
}