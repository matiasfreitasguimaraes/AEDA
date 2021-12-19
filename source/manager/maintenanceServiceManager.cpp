#include "maintenanceServiceManager.h"

/**
 * @brief reads information of the maintenance services from a file
 * @param file the file containing the information related to the maintenance services
 */
void MaintenanceServiceManager::read(ifstream &file) {
    unsigned year, month, day, hour, minute;
    string type, responsible;
    char sep;

    if (file.is_open()) {
        cout << "Successfully opened the file! \n";

        while(!file.eof()) {
            file >> type >> year >> sep >> month >> sep >> day >> hour >> sep >> minute >> responsible;
            DateTime date(year, month, day, hour, minute);
            MaintenanceService service(type, date, responsible);
            maintenanceServices.insert(service);
        }
    } else { cout << "Couldn't open file \n";}
}

/**
 * @brief adds a service
 * @param service the service to be added
 */
void MaintenanceServiceManager::add(MaintenanceService service) {
    maintenanceServices.insert(service);
}

/**
 * @brief removes a service
 * @param serviceToRemove the service to be removed
 */
void MaintenanceServiceManager::remove(MaintenanceService serviceToRemove) {
    maintenanceServices.erase(serviceToRemove);
}

/**
 * @brief writes the changes made to a  file
 * @param file the file where the changes are stored
 */
void MaintenanceServiceManager::write(ostream &file) {
    for (MaintenanceService service: maintenanceServices) {
        file << service.getType() << " " << service.getDate() << " " << service.getResponsible() << endl;
    }
}

/**
 * @brief prints all the services and their information
 */
void MaintenanceServiceManager::show() {
    for (MaintenanceService service: maintenanceServices) {
        cout << service << endl;
    }
}
