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
#include <vector>

void clearScreen();
void printMenu();
void InternalMenu(User usuario);
void sensorMenu();
void cameraMenu();
void initializeUsers(std::vector<User*>& users);
int getOption(int min, int max);
void manageMenuSelection(User usuario, airQualitySensor airSensor, humiditySensor humSensor, lightSensor ligSensor, RGBCamera rgbCam, ThermalCamera thermalCam);
void manageInternalMenu(User usuario, airQualitySensor airSensor, humiditySensor humSensor, lightSensor ligSensor,RGBCamera rgbCam, ThermalCamera thermalCam);
void manageSensorMenu(airQualitySensor airSensor, humiditySensor humSensor, lightSensor ligSensor);
void manageCameraMenu(RGBCamera rgbCamera, ThermalCamera thermalCamera);
bool loginForm(User usuario);


#endif //DASHBOARD_H