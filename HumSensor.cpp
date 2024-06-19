#include "HumSensor.h"
#include "Sensor.h"
#include <iostream>

humiditySensor::humiditySensor(bool on, int id) : Sensor(on, id, Sensor::HUMIDITY){
}

void humiditySensor::collectData(){
    if(on_){
        data_[0] = (int)(rand() % 101);
    } else {
        std::cout << getType() << "Sensor" << id_ << "is OFF" << std::endl;
    }
}

int humiditySensor::getHumidity() const{
    return data_[0];
}

std::ostream& operator<<(std::ostream& os, humiditySensor& sensor){
    os << " ------- " << sensor.getType() << "Data id: " << sensor.getId() << " ----- " << std::endl;
    os << " -   Status: " << (sensor.isOn() ? "ON -" : "OFF -") << std::endl;
    os << " -   Humidity: " << sensor.getHumidity() << " %" << std::endl;
    os << " ---------------------------------";
    return os;
}