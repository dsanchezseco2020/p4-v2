#include "LightSensor.h"
#include <iostream>
#include <cstdlib>  // Para srand() y rand()
#include <ctime>    // Para time()

using namespace std;

int main(){
    
    srand(static_cast<unsigned int>(time(0)));  // Inicializa el generador de números aleatorios
    lightSensor lightSensor1(true, 1);

    cout << lightSensor1 << endl;
    lightSensor1.collectData();
    cout << lightSensor1 << endl;
    
    return 0;

}