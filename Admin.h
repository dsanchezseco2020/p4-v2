#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

class admin : public User{
public:
    admin();
    admin(const std::string& username, const std::string& NIF, const unsigned int password);

    //void addUser()
    //void removeUser()
    void checkSensors();

};


#endif //ADMIN_H