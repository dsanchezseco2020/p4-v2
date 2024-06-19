#include "AirSensor.h"
#include "Sensor.h"
#include <iostream>

airQualitySensor::airQualitySensor(bool on, int id) : Sensor(on, id, Sensor::AIR_QUALITY), airQualityIndex_(0){
}

void airQualitySensor::collectData(){
    if(on_) {
        int air_quality_index = rand() % 500 + 1;
        setData(0, air_quality_index);
    }
    else{
        std::cout << getType() << "Sensor (id = "<< id_ <<") is OFF" << std::endl;
    };
}

int airQualitySensor::getAirQualityIndexNumber() const{
    return data_[0];
}

std::string airQualitySensor::getAirQualityString(){
    int numero = data_[0];
    if (numero > 0 && numero <= 50) {
        return "Good";
    } else if (numero >= 51 && numero <= 100) {
        return "Moderate";
    } else if (numero >= 101 && numero <= 150) {
        return "Poor";
    } else if (numero >= 151 && numero <= 200) {
        return "Unhealthy";
    } else if (numero >= 201 && numero <= 300) {
        return "Very Unhealthy";
    } else if (numero >= 301 && numero <= 500) {
        return "Hazardous";
    } else {
        return "None";
    }
}

std::ostream& operator<<(std::ostream& os, airQualitySensor& sensor){
    os << "-------------------"<< sensor.getType() << "Data (id = " << sensor.getId() << " ) ------" << std::endl;
    os << " Status: "<< (sensor.isOn() ? "ON": "OFF") << std::endl;
    os << " Air Quality Index: " << sensor.getAirQualityIndexNumber() << "(" << sensor.getAirQualityString() << ")" << std::endl;
    os << "------------------------------------------" << std::endl;
    return os;
}