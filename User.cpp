#include "User.h"

User::User(){
    username_ = "";
    NIF_ = "";
    password_ = 0;
    privilegio_ = GUEST;
}

User::User(const std::string& username, const std::string& NIF, const unsigned int password, Privilegios privilegios)
    : username_(username), NIF_(NIF), password_(password), privilegio_(privilegios) {}


std::string User::getUsername() const {
    return username_;
}

void User::setUsername(std::string newUsername){
    username_ = newUsername;
}

std::string User::getNIF() const {
    return NIF_;
}

void User::setNIF(std::string newNIF){
    NIF_ = newNIF;
}

unsigned int User::getPassword() const{
    return password_;
}

void User::setPassword(unsigned int newPass){
    password_ = newPass;
}

std::string User::getPrivileges() const {
    switch (privilegio_) {
        case ADMIN: return "ADMIN";
        case EMPLOYEE: return "EMPLOYEE";
        case GUEST: return "GUEST";
        default: return "UNKNOWN";
    }
}

void User::setPrivileges(std::string newPrivileges){
    if(newPrivileges == "ADMIN"){
        privilegio_ = User::ADMIN;
    } else if(newPrivileges == "EMPLOYEE"){
        privilegio_ = User::EMPLOYEE;
    } else if(newPrivileges == "GUEST"){
        privilegio_ = User::GUEST;
    }
}

bool User::operator==(const User &other) const{
    return (username_ == other.username_ && NIF_ == other.NIF_ && password_ == other.password_);
}

std::ostream& operator<<(std::ostream& os, const User& user){
    os << user.getUsername() << " " << user.getNIF() << " " << user.getPassword() << " " << user.getPrivileges() << std::endl;
    return os;
}

