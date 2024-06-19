#ifndef THERMCAM_H
#define THERMCAM_H

#include "Sensor.h"
#include <vector>

class ThermalCamera : public Sensor {
    public:
        ThermalCamera(bool on, int id);

        std::string collectData();

        friend std::ostream& operator<<(std::ostream& os,  ThermalCamera& camera);

   
};

#endif // THERMCAM_H