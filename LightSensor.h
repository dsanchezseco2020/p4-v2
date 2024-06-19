#ifndef LIGHT_H
#define LIGHT_H

#include "Sensor.h"

class lightSensor : public Sensor {
    public: 
        lightSensor(bool on, int id);

        void collectData();
        int getLight() const;
        std::string getLightString();

        friend std::ostream& operator<<(std::ostream& os, lightSensor& sensor);

};



#endif //LIGHT_H