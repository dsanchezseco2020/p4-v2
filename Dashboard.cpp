#include "Sensor.h"
#include "AirSensor.h"
#include "HumSensor.h"
#include "LightSensor.h"
#include "RGBCamera.h"
#include "ThermalCamera.h"
#include "User.h"
#include "Admin.h"
#include "Employee.h"
#include "Dashboard.h"

#include <iostream>
#include <vector>
#include <cstdlib> // Para std::system


using namespace std;



// Esta es una funcion simple que con directivas de preprocesado
// analiza en que sistema operativo se ejecuta el codigo para poder borrar
// la terminal

void clearScreen() { 
    #if defined(_WIN32) || defined(_WIN64)
        std::system("cls");
    #elif defined(__linux__) || defined(__APPLE__)
        std::system("clear");
    #else
        std::cerr << "No se puede limpiar la pantalla en este sistema operativo." << std::endl;
    #endif
}


void printMenu(){
    clearScreen();
    cout << " ******************* GREENHOUSE ******************** " << endl;
    cout << " *                                                 * " << endl;
    cout << " *                                                 * " << endl;
    cout << " *                                                 * " << endl;
    cout << " *          ~ WELCOME TO THE GREENHOUSE ~          * " << endl;
    cout << " *                                                 * " << endl;
    cout << " *                                                 * " << endl;
    cout << " *     1.- Login                                   * " << endl;
    cout << " *     2.- Exit                                    * " << endl;
    cout << " *                                                 * " << endl;
    cout << " *                                                 * " << endl;
    cout << " *                                                 * " << endl;    
    cout << " *************************************************** " << endl;

};

int getOption(int min, int max) {
    int option;
    string optionStr;
    bool exit = false;
    while(!exit){
        cout << "Select an option: ";
        cin >> optionStr;
        try{
            option = stoi(optionStr);
            if (option >= min || option <= max || optionStr == "exit"){
                exit = true;
            }
            else{
                cout << "Invalid option! Select an option between 1 or 2";
            }
        } catch(exception& e){
            if (optionStr == "exit"){
                exit = true;
            } else {
                cout << "Invalid option! Select an option between 1 or 2";
            }
        }    
    }
    if (optionStr == "exit"){
        return -1;
    } else {
        return option;
    }
}

void manageMenuSelection(User usuario, airQualitySensor airSensor, humiditySensor humSensor,
                    lightSensor ligSensor, RGBCamera rgbCam, ThermalCamera thermalCam){ // Controlo las opciones del menu de inicio
    int option = getOption(1, 2); 
    if (option == 1){
        cout << " Login Form!" << endl; 
        manageInternalMenu(usuario, airSensor, humSensor, ligSensor, rgbCam, thermalCam);
    } else if (option == 2){ 
        cout << " Exiting! Bye!" << endl;
        exit(EXIT_SUCCESS);
    }
}


bool loginForm(User usuario){ //Hago un formulario de login. Mas tarde comparara con la base de datos
    std::string username;
    std::string NIF;
    unsigned int password;
    
    
    clearScreen();
    cout << "Hi!! This is the login form for the greenhouse" << endl;
    cout << "\nIntroduce your username: ";
    cin >> username;
    cout << "\nIntroduce your NIF: ";
    cin >> NIF;
    cout << "\nIntroduce your password: ";
    cin >> password;
    
    User loginUser;
    loginUser.setUsername(username);
    loginUser.setNIF(NIF);
    loginUser.setPassword(password);

    if (usuario == loginUser){
        cout << "\n Login successful!, Welcome to the greenhouse system,  " << username << endl;
        return true;
    } else {
        cout << "\n Login failed, Incorrect username, NIF, or password." << endl;
        exit(EXIT_FAILURE);
    }
}

void InternalMenu(User usuario){ //muestra distintos menus en funcion de los privilegios del usuario
    if (loginForm(usuario)){
        clearScreen();
        cout << " ******************* GREENHOUSE ******************** " << endl;
        cout << " *                                                 * " << endl;
        cout << " *  ~ WELCOME TO THE GREENHOUSE ~                  * " << endl;
        cout << " *                                                 * " << endl;
        cout << " *    1.- Sensors                                  * " << endl;
        cout << " *                                                 * " << endl;
        cout << " *                                                 * " << endl;
        if (usuario.getPrivileges() == "ADMIN"){
            cout << " *    2.- Cameras                                  * " << endl;
            cout << " *                                                 * " << endl;
            cout << " *                                                 * " << endl;
            cout << " *    3.- Team Management                          * " << endl;
        }
        cout << " *                                                 * " << endl;
        cout << " *                                                 * " << endl;
        cout << " *                                                 * " << endl;
        cout << " *    Type exit to quit                            * " << endl;
        cout << " *                                                 * " << endl;    
        cout << " *************************************************** " << endl;

    }
}

void manageInternalMenu(User usuario, airQualitySensor airSensor, humiditySensor humSensor,
                    lightSensor ligSensor, RGBCamera rgbCam, ThermalCamera thermalCam){ // Control del primer menu interno
    InternalMenu(usuario);
    if(usuario.getPrivileges() == "ADMIN"){
        int option = getOption(1, 3);
        if (option == 1){
            cout << " Sensors Menu!" << endl;
            manageSensorMenu(airSensor, humSensor, ligSensor);
        } else if (option == 2){
            cout << " Cameras Menu!" << endl;
            manageCameraMenu(rgbCam, thermalCam);
        } else if (option == 3){
            cout << " Team Management Menu!" << endl;
        } else if (option == -1){
            cout << " Exiting! Bye!" << endl;
            exit(EXIT_SUCCESS);
        } else {
            cout << " Invalid option!" << endl;
        };
    } else {
        int option = getOption(1, 1);
        if (option == 1){
            cout << " Sensors Menu!" << endl;
            manageSensorMenu(airSensor, humSensor, ligSensor);
        }else if (option == -1){
            cout << " Exiting! Bye!" << endl;
            exit(EXIT_SUCCESS);
        } else {
            cout << " Invalid option!" << endl;
        }
    }
}


void sensorMenu(){
    clearScreen();
    cout << " ********************* SENSORS ********************* " << endl;
    cout << " *                                                 * " << endl;
    cout << " *    ~ SENSORS MENU ~                             * " << endl;
    cout << " *                                                 * " << endl;
    cout << " *    1.- Air Sensor                               * " << endl;
    cout << " *                                                 * " << endl;
    cout << " *    2.- Humidity Sensor                          * " << endl;
    cout << " *                                                 * " << endl;
    cout << " *    3.- Light Sensor                             * " << endl;
    cout << " *                                                 * " << endl;
    cout << " *                                                 * " << endl;
    cout << " *                                                 * " << endl;
    cout << " *    Type exit to quit                            * " << endl;
    cout << " *                                                 * " << endl;    
    cout << " *************************************************** " << endl;
}

void manageSensorMenu(airQualitySensor airSensor, humiditySensor humSensor,lightSensor ligSensor){ // Control del menu de sensores
    sensorMenu();
    int option = getOption(1, 3);
    if (option == 1){
        airSensor.collectData();
        cout << airSensor << std::endl;
    } else if (option == 2){
        humSensor.collectData();
        cout << humSensor << std::endl;
    } else if (option == 3){
        ligSensor.collectData();
        cout << ligSensor << std::endl;
    } else if (option == -1){
        cout << " Exiting! Bye!" << endl;
        exit(EXIT_SUCCESS);
    } else {
        cout << " Invalid option!" << endl;
    }
}

void cameraMenu(){
    clearScreen();
    cout << " ********************* SENSORS ********************* " << endl;
    cout << " *                                                 * " << endl;
    cout << " *    ~ SENSORS MENU ~                             * " << endl;
    cout << " *                                                 * " << endl;
    cout << " *    1.- RGB Camera                               * " << endl;
    cout << " *                                                 * " << endl;
    cout << " *    2.- Thermal Camera                           * " << endl;
    cout << " *                                                 * " << endl;
    cout << " *                                                 * " << endl;
    cout << " *                                                 * " << endl;
    cout << " *                                                 * " << endl;
    cout << " *    Type exit to quit                            * " << endl;
    cout << " *                                                 * " << endl;    
    cout << " *************************************************** " << endl;
}

void manageCameraMenu(RGBCamera rgbCam, ThermalCamera thermalCam){ // Control del menu de sensores
    cameraMenu();
    int option = getOption(1, 2);
    if (option == 1){
        cout << rgbCam << std::endl;
    } else if (option == 2){
        cout << thermalCam << std::endl;
    } else if (option == -1){
        cout << " Exiting! Bye!" << endl;
        exit(EXIT_SUCCESS);
    } else {
        cout << " Invalid option!" << endl;
    }


}