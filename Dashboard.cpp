#include "Sensor.h"
#include "AirSensor.h"
#include "HumSensor.h"
#include "LightSensor.h"
#include "RGBCamera.h"
#include "ThermalCamera.h"
#include "User.h"
#include "Admin.h"
#include "Employee.h"

#include <iostream>
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
    bool exit = false;
    while(!exit){
        cout << "Select an option: ";
        cin >> option;

        if (option >= 1 || option <= 2){
            exit = true;
        }
        else{
            cout << "Invalid option! Select an option between 1 or 2";
        }
    }
    return option;
}

void loginForm(User usuario){ //CAMBIAR A BOOL
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
    }
    cout << "\n Login failed, Incorrect username, NIF, or password." << endl;
}

void manageMenuSelection(User usuario){
    int option = getOption(1, 2);
    if (option == 1){
        cout << " Login Form!" << endl; 
        loginForm(usuario);
    } else if (option == 2){
        cout << " Exiting asd! Bye!" << endl;
        exit(EXIT_SUCCESS);
    }
}

