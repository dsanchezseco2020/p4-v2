#include "Dashboard.h"
#include "Admin.h"
#include "User.h"

#include <iostream>

int main(){
    admin admin1("", "", 0);
    admin1.setUsername("admin1");
    admin1.setNIF("1324120A");
    admin1.setPassword(123456);
    admin1.setPrivileges("ADMIN");
    printMenu();
    manageMenuSelection(admin1);
}