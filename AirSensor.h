#ifndef AIR_QUALITY_SENSOR_H
#define AIR_QUALITY_SENSOR_H

#include "Sensor.h"

class airQualitySensor : public Sensor {
public:
    airQualitySensor(bool on, int id);

    void collectData();
    int getAirQualityIndexNumber() const;
    std::string getAirQualityString();

    friend std::ostream& operator<<(std::ostream& os,airQualitySensor& sensor);

private:
    int airQualityIndex_;
};

#endif // AIR_QUALITY_SENSOR_H