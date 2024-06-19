#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "Sensor.h"

class humiditySensor : public Sensor{
    public:
        humiditySensor(bool on, int id);

        void collectData();
        int getHumidity() const;

        friend std::ostream& operator<<(std::ostream& os, humiditySensor& sensor);

};



#endif //HUMIDITY_H