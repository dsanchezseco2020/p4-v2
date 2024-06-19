#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "Sensor.h"
#include "AirSensor.h"
#include "HumSensor.h"
#include "LightSensor.h"
#include "RGBCamera.h"
#include "ThermalCamera.h"
#include "User.h"
#include "Admin.h"
#include "Employee.h"

void clearScreen();
void printMenu();
void InternalMenu(User usuario);
int getOption(int min, int max);
void manageMenuSelection(User usuario);
void manageInternalMenu(User usuario);
void loginForm(User usuario);


#endif //DASHBOARD_H