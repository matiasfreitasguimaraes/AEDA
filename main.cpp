//
// Created by Matias Freitas Guimarães on 29/11/2021.
//

#include <iostream>
#include <climits>
#include <algorithm>

#include "airportSystem/plane.h"

int main() {
    vector<Flight> flights;
    for (int i = 0; i < 5; i++) {
        Flight flight(i, "01/12/2021", "02/12/2021", "Portugal", "Spain");
        flights.push_back(flight);
    }
    Plane plane(10, "A101", "123", flights);
    cout << plane << endl;
    return 0;
}