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
#include <set>


void initializeUsers(std::multiset<User*>& users);
void clearScreen();
void printMenu();
int getOption(int min, int max);
void manageMenuSelection(std::multiset<User*>& users, airQualitySensor airSensor, humiditySensor humSensor, lightSensor ligSensor, RGBCamera rgbCam, ThermalCamera thermalCam);
bool loginForm(std::multiset<User*> users, User*& loggedUser);
void InternalMenu(std::multiset<User*>& users, User*& loggedUser);
void manageInternalMenu(std::multiset<User*>& users ,airQualitySensor airSensor, humiditySensor humSensor, lightSensor ligSensor,RGBCamera rgbCam, ThermalCamera thermalCam);
void sensorMenu();
void manageSensorMenu(airQualitySensor airSensor, humiditySensor humSensor, lightSensor ligSensor);
void cameraMenu();
void manageCameraMenu(RGBCamera rgbCamera, ThermalCamera thermalCamera);
void staffMenu();
void manageStaffMenu(std::multiset<User*> users);
void addNewUserForm(std::multiset<User*> users);
//void removeUserForm(std::set<User*> users);
void listStaff(std::multiset<User*> users);



#endif //DASHBOARD_H