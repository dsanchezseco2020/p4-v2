#include "LightSensor.h"
#include "Sensor.h"
#include <iostream>

lightSensor::lightSensor(bool on, int id) : Sensor(on, id, Sensor::LIGHT_SENSOR ){
}

void lightSensor::collectData(){
    if(on_){
        data_[0] = (int)(rand() % 2501);
    } else {
        std::cout << getType() << "Sensor " << id_ << "is OFF" << std::endl;
    }
}

int lightSensor::getLight() const{
    return data_[0];
}

std::string lightSensor::getLightString() {
  int lightvalue = data_[0];
  if (lightvalue == 0) {
      return "No data yet";
    } else if (lightvalue <= 50) {
      return "Very low lighting or almost darkness"; 
    } else if (lightvalue <= 200) {
      return "Low lighting";
    } else if (lightvalue <= 500) {
      return "Moderate lighting";
    } else if (lightvalue <= 1000) {
      return "High lighting, like indirect sunlight on a cloudy day";
    } else if (lightvalue <= 2000) {
      return "Very high lighting";
    } else if (lightvalue <= 2500) {
      return "Extremely high lighting";
    } else {
      return "Wrong value.";
    }
}

std::ostream& operator<<(std::ostream& os, lightSensor& sensor){
    os << " ------- " << sensor.getType() << " Data id: " << sensor.getId() << " -" << std::endl;
    os << " -   Status: " << (sensor.isOn() ? "ON -" : "OFF -") << std::endl;
    os << " -   Light: " << sensor.getLight() << " " << sensor.getLightString() << std::endl;
    os << " ---------------------------------";
    return os;
}