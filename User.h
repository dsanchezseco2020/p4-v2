#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

class User {
    public:
        enum Privilegios{
            ADMIN, 
            EMPLOYEE,
            GUEST
        };

        User();
        explicit User(const std::string& username, const std::string& NIF, const unsigned int password, Privilegios privilegios);

        std::string getUsername() const;
        std::string getNIF() const;
        unsigned int getPassword() const;
        std::string getPrivileges() const;

        void setUsername(std::string newUsername);
        void setNIF(std::string newNIF);
        void setPassword(unsigned int newPass);
        void setPrivileges(std::string newPrivileges);
        bool operator== (const User& other) const;
        friend std::ostream& operator<<(std::ostream& os, const User& user);
    protected:
        std::string username_;
        std::string NIF_;
        unsigned int password_;
        Privilegios privilegio_;

};

#endif //USER_H