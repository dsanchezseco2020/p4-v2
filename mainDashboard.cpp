#include "Dashboard.h"
#include "User.h"

#include <iostream>

int main(){

    User admin1("", "", 0, User::GUEST);
    User employee1("", "", 0, User::GUEST);
    airQualitySensor airSensor(true, 1);
    humiditySensor humSensor(true, 2);
    lightSensor ligSensor(true, 3);
    RGBCamera rgbCam(true, 4);
    ThermalCamera thermCam(true, 5);
    admin1.setUsername("1");
    admin1.setNIF("2");
    admin1.setPassword(3);
    admin1.setPrivileges("ADMIN");
    employee1.setUsername("2");
    employee1.setNIF("3");
    employee1.setPassword(4);
    employee1.setPrivileges("EMPLOYEE");
    printMenu();
    manageMenuSelection(employee1 , airSensor, humSensor, ligSensor, rgbCam, thermCam);
}