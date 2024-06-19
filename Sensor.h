#ifndef SENSOR_H
#define SENSOR_H
#include <string>

class Sensor {
public:
    enum sensorType {
        TEMPERATURE, 
        AIR_QUALITY, 
        HUMIDITY, 
        LIGHT_SENSOR, 
        RGB_CAMERA,
        THERMAL_CAMERA,
        NONE
    };

    Sensor();
    explicit Sensor(bool on, int id, sensorType type);
    virtual ~Sensor();
     

    bool isOn();
    void turnOn();
    void turnOff();
    int getData(int index);
    int getId();
    std::string getType() const ;
    void setData(int index, int value);
    void setId(int newId);
    void setType(std::string newType);


    // Operadores sobrecargados

    bool operator==(const Sensor &other) const;
    bool operator<(const Sensor &other) const;
    friend std::ostream& operator<<(std::ostream& os, const Sensor& sensor);


protected:
    bool on_;
    int data_[10];
    int id_;
    sensorType type_;

};

#endif // SENSOR_H