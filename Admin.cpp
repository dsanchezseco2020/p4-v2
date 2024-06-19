#include "Admin.h"
#include "User.h"
#include <iostream>

admin::admin() : User(){
    privilegio_ = ADMIN;
}

admin::admin(const std::string& username, const std::string& NIF, const unsigned int password)
    : User(username, NIF, password, ADMIN){}

void admin::checkSensors(){
    std::cout << "Sensores includas las camaras" << std::endl;
}