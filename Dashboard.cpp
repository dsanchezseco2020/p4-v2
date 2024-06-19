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
#include <set>
#include <algorithm>
#include <cstdlib> // Para std::system


using namespace std;

void initializeUsers(std::multiset<User*>& users) {
    // Creo un "superAdmin" de testeo para inicializar el set de usuarios
    User* superAdmin = new User("1", "2", 3, User::ADMIN);
    User* employee = new User("2", "4", 3, User::EMPLOYEE);

    // Añado el usuario al set de usuarios
    cout << "Se estan añadiendo aqui" << endl;
    users.insert(superAdmin);
    users.insert(employee);
}

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

void manageMenuSelection(std::multiset<User*>& users, airQualitySensor airSensor, humiditySensor humSensor,
                    lightSensor ligSensor, RGBCamera rgbCam, ThermalCamera thermalCam){ // Controlo las opciones del menu de inicio
    int option = getOption(1, 2); 
    if (option == 1){
        cout << " Login Form!" << endl; 
        manageInternalMenu(users , airSensor, humSensor, ligSensor, rgbCam, thermalCam);
    } else if (option == 2){ 
        cout << " Exiting! Bye!" << endl;
        exit(EXIT_SUCCESS);
    }
}


bool loginForm(std::multiset<User*> users, User*& loggedUser){ //Hago un formulario de login. Mas tarde comparara con la base de datos
    std::string username;
    std::string NIF;
    unsigned int password;
    bool loginSuccessful = false;

    
    
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

    for (const User* usuario : users) {
        if (*usuario == loginUser) {
            cout << "\n Login successful!, Welcome to the greenhouse system, " << usuario->getUsername() << endl;
            loggedUser = const_cast<User*>(usuario); //Creo un puntero con el usuario que se ha logeado
            loginSuccessful = true;
            break;
        } 
    }
    if(!loginSuccessful){
        cout << "\n Invalid username or password, try again" << endl;
    }  
    return loginSuccessful;
}

void InternalMenu(std::multiset<User *> &users, User *&loggedUser)
{ // muestra distintos menus en funcion de los privilegios del usuario
    if (loginForm(users, loggedUser))
    {
        clearScreen();
        cout << " ******************* GREENHOUSE ******************** " << endl;
        cout << " *                                                 * " << endl;
        cout << " *  ~ WELCOME TO THE GREENHOUSE ~                  * " << endl;
        cout << " *                                                 * " << endl;
        cout << " *    1.- Sensors                                  * " << endl;
        cout << " *                                                 * " << endl;
        cout << " *                                                 * " << endl;
        if (loggedUser->getPrivileges() == "ADMIN")
        {
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

void manageInternalMenu(std::multiset<User*>& users, airQualitySensor airSensor, humiditySensor humSensor,
                    lightSensor ligSensor, RGBCamera rgbCam, ThermalCamera thermalCam){ // Control del primer menu interno
    User* loggedUser = nullptr;
    InternalMenu(users, loggedUser);
    if(loggedUser != nullptr){
        if(loggedUser->getPrivileges() == "ADMIN"){
            int option = getOption(1, 3);
            if (option == 1){
                cout << " Sensors Menu!" << endl;
                manageSensorMenu(airSensor, humSensor, ligSensor);
            } else if (option == 2){
                cout << " Cameras Menu!" << endl;
                manageCameraMenu(rgbCam, thermalCam);
            } else if (option == 3){
                manageStaffMenu(users);
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
    } else {
        cout << " NULL PTR" << endl;
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

void staffMenu(){
    clearScreen();
    cout << " ********************* STAFF MENU ********************* " << endl;
    cout << " *                                                    * " << endl;
    cout << " *    ~ STAFF MENU ~                                  * " << endl;
    cout << " *                                                    * " << endl;
    cout << " *    1.- Add Staff                                   * " << endl;
    cout << " *                                                    * "<< endl;
    cout << " *    2.- Remove Staff                                * " << endl;  
    cout << " *                                                    * " << endl;
    cout << " *    3.- List Staff                                  * " << endl;
    cout << " *                                                    * " << endl;
    cout << " *    Type exit to quit                                                * " << endl;
    cout << " *                                                    * " << endl;
    cout << " ****************************************************** " << endl;
}

void manageStaffMenu(std::multiset<User*> staffList) {// Control del menu de staff
    staffMenu();
    int option = getOption(1, 3);
    if (option == 1){
        addNewUserForm(staffList);
    } else if (option == 2) {
        //removeUserForm(staffList);
    } else if (option == 3){
        listStaff(staffList);
    } else if (option == -1){
        cout << " Exiting! Bye!" << endl;
        exit(EXIT_SUCCESS);
    } else {
        cout << " Invalid option!" << endl;
    }
    
};

void addNewUserForm(std::multiset<User*> staffList){

   
    string username, newNIF, privilegioStr;
    unsigned int password = 0; 
    User::Privilegios privilegio;

    clearScreen();
    listStaff(staffList);
    cout << endl;
    cout << "\nIntroduce new user's username: ";
    cin >> username;
    cout << "\nIntroduce new user's NIF: ";
    cin >> newNIF;
    cout << "\nIntroduce new user's password: ";
    cin >> password;
    cout << "\nIntroduce new user's privilege (ADMIN, EMPLOYEE, or GUEST): ";
    cin >> privilegioStr;

    // Convert the privilege string to the corresponding enum value
    if (privilegioStr == "ADMIN") {
        privilegio = User::ADMIN;
    } else if (privilegioStr == "EMPLOYEE") {
        privilegio = User::EMPLOYEE;
    } else if (privilegioStr == "GUEST") {
        privilegio = User::GUEST;
    } else {
        cout << "Invalid privilege level!" << endl;
        return;
    }

    for (User* user : staffList){
        if (user->getNIF() == newNIF){ // Comparo solo el NIF ya que es un documento unipersonal
            cout << "User already exists!" << endl;
            cout << "NIF:" << user->getNIF() << " | " << newNIF << endl;
            listStaff(staffList);
            exit(EXIT_FAILURE);
        } else if (user->getUsername() != username ){ //El nombre de usuario no se puede repetir, entonces de esta manera compruebo que el NIF y el username
        //son diferentes
            User* newUser = new User(username, newNIF, password, privilegio);
            newUser->setUsername(username);
            newUser->setNIF(newNIF);  
            newUser->setPassword(password);
            newUser->setPrivileges(privilegio);
            staffList.insert(newUser);

        } else {
            cout << "User already exists!" << endl;
            if (user->getUsername() == username){
                cout << "Username:" << user-> getUsername() << " | " << username << endl;
            } else if (user->getNIF() == newNIF){
                cout << "NIF:" << user->getNIF() << " | " << newNIF << endl;
            }
            exit(EXIT_FAILURE);
        }
    }
    listStaff(staffList);
}

/*void removeUserForm(std::set<User*> staffList) {
    std::string NIF; /// ESTO PRODUCE UNA VIOLACION DE SEGMENTO
    std::cout << "Introduce the NIF of the user to remove: ";
    std::cin >> NIF;

    // Crear una copia de la lista original
    std::set<User*> tempStaffList = staffList;

    // Lista temporal para almacenar los punteros a los objetos User que se eliminarán
    std::set<User*> toRemove;

    // Eliminar los usuarios con el NIF especificado de la copia
    tempStaffList.erase(
        std::remove_if(tempStaffList.begin(), tempStaffList.end(),
                       [&NIF, &toRemove](User* user) {
                           if (user != nullptr && user->getNIF() == NIF) {
                               toRemove.insert(user);
                               return true;
                           }
                           return false;
                       }),
        tempStaffList.end());

    // Asignar la copia modificada de vuelta a la lista original
    staffList = tempStaffList;

    // Eliminar los objetos User de la lista toRemove
    for (User* user : toRemove) {
        delete user;
    }
}
*/

void listStaff(std::multiset<User*> staffList){
    for(User* user : staffList){
        cout << user->getUsername() << " "  << user->getNIF() << " "<< user->getPrivileges() << endl;
    }
}
