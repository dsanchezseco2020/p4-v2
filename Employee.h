#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "User.h"

class employee : public User{
public:
    employee(const std::string& username, const std::string& NIF, const unsigned int password);
    void checkSensors();

};


#endif //EMPLOYEE_H