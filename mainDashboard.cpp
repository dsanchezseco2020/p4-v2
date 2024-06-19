#include "Dashboard.h"
#include "User.h"

#include <iostream>

int main(){


    std::multiset<User*> users;
    initializeUsers(users);
    airQualitySensor airSensor(true, 1);
    humiditySensor humSensor(true, 2);
    lightSensor ligSensor(true, 3);
    RGBCamera rgbCam(true, 4);
    ThermalCamera thermCam(true, 5);
    printMenu();
    manageMenuSelection(users, airSensor, humSensor, ligSensor, rgbCam, thermCam);
    for (User* user : users) {
        delete user;
    }

    return 0;
}