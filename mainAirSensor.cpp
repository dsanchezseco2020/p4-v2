#include "AirSensor.h"
#include <iostream>
#include <cstdlib>  // Para srand() y rand()
#include <ctime>    // Para time()

using namespace std;

int main(){

    srand(static_cast<unsigned int>(time(0)));  // Inicializa el generador de números aleatorios
    airQualitySensor aSensor1(true, 1);

    std::cout << aSensor1 << std::endl;
    aSensor1.collectData();
    std::cout << aSensor1 << std::endl;
}