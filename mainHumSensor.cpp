#include "HumSensor.h"
#include <iostream>
#include <cstdlib>  // Para srand() y rand()
#include <ctime>    // Para time()

using namespace std;
int main(){
    
     srand(static_cast<unsigned int>(time(0)));  // Inicializa el generador de números aleatorios
    humiditySensor humSensor(true, 1);

    cout << humSensor << endl;
    humSensor.collectData();
    cout << humSensor << endl;
    
    return 0;

}