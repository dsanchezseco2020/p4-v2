#ifndef RGBCAM_H
#define RGBCAM_H

#include "Sensor.h"
#include <vector>

class RGBCamera : public Sensor {
    public:
        RGBCamera(bool on, int id);

        std::string collectData();

        friend std::ostream& operator<<(std::ostream& os,  RGBCamera& camera);

   
};

#endif // RGBCAM_H