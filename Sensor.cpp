#include "Sensor.h"
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

Sensor::Sensor(){
    on_ = true;
    id_ = 0;
    type_ = TEMPERATURE;
    for (int i = 0; i < 10; ++i){
        data_[i] = 0;
    }
}

Sensor::Sensor(bool on, int id, sensorType type) : on_(on), id_(id), type_(type){
    for (int i = 0; i < 10; i++) {
        data_[i] = 0;
    }
}

Sensor::~Sensor(){
}


bool Sensor::isOn(){
    return on_;
}

void Sensor::turnOn(){
    on_ = true;
}

void Sensor::turnOff(){
    on_ = false;
}

int Sensor::getData(int index) {
    return data_[index];
}


int Sensor::getId(){
    return id_;
}

std::string Sensor::getType() const {
    std::string typesString;
    switch(type_){
        case TEMPERATURE:
            return "Temperature Sensor";
        case AIR_QUALITY:
            return "Air Quality Sensor";
        case HUMIDITY:
            return "Humidity Sensor";
        case LIGHT_SENSOR:
            return "Light Sensor";
        case RGB_CAMERA:
            return "RGB Camera";
        case THERMAL_CAMERA:
            return "Themal Camera";  
        default:
            return "None";
    }
}

void Sensor::setData(int index, int value){
    if (index >= 0 && index <= 9){
        data_[index] = value;
    }
    else 
    {
        std::cout << "Index out of range" << std::endl;
    }
}

void Sensor::setId(int newID){
    id_ = newID;
}

void Sensor::setType(std::string newType){
    if (newType == "TEMPERATURE"){
        type_ = TEMPERATURE;
    }   
    else if (newType == "AIR QUALITY"){
        type_ = AIR_QUALITY;
    }
    else if (newType == "HUMIDITY"){
        type_ = HUMIDITY;
    }
    else if (newType == "LIGHT SENSOR"){
        type_ = LIGHT_SENSOR;
    }
    else if (newType == "RGB CAMERA"){
        type_ = RGB_CAMERA;
    }
    else if (newType == "THERMAL CAMERA"){
        type_ = THERMAL_CAMERA;
    }
    else{
        type_ = NONE;
    }
}


// Operadores sobrecargados


bool Sensor::operator==(const Sensor &other) const{
    return(type_ == other.type_) && (id_ == other.id_);
}

bool Sensor::operator<(const Sensor &other) const{
    return id_ < other.id_;
}

std::ostream& operator<<(std::ostream& os, const Sensor& sensor){
    os << "---- SENSOR ----" << std::endl;
    os << " On: " << std::boolalpha << sensor.on_ << std::endl;
    os << "Data [";
    for (int i = 0; i < 10; i++){
        os << std::setw(2) << sensor.data_[i];
        if(i != 9) {
            os << ", ";
        }
    }
    os << "]" << std::endl;
    os << "Type: " << sensor.getType() << std::endl;
    os << " -------------- " << std::endl;
    return os;
}

