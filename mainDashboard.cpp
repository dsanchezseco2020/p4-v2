#include "Dashboard.h"
#include "User.h"

#include <iostream>

int main(){
    User admin1("", "", 0, User::GUEST);
    admin1.setUsername("admin1");
    admin1.setNIF("1324120A");
    admin1.setPassword(123456);
    admin1.setPrivileges("ADMIN");
    printMenu();
    manageMenuSelection(admin1);
}