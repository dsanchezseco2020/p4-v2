#include "Sensor.h"
#include <iostream>
#include <typeinfo>


using namespace std;

int main(){
    // Pruebo a crear un Sensor

    Sensor sensor1(true, 1, Sensor::TEMPERATURE); // sensor(on, id, type)
    std::cout << sensor1 << std::endl;

    // Datos

    sensor1.setData(0, 25);
    sensor1.setData(1, 30);

    std::cout << "Datos recopilados " << std::endl << sensor1 << std::endl;

    sensor1.getId();
    std::cout << "Sensor 1 Type: " << sensor1.getType() << std::endl;
    sensor1.turnOff();
    std::cout << sensor1 << std::endl;

    return 0;
}