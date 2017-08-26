#ifndef SENSOR_MANAGER_H_
    #define SENSOR_MANAGER_H_
    
#include "sensor.h"

#define MAX_SENSORS 32

class sensorManager {
 private:
    sensor* _sensors[MAX_SENSORS];
    double _values[MAX_SENSORS];
    uint8_t _numSensors;

 public:
    sensorManager();
    void init();
    void update();
    
    uint8_t registerSensor(sensor* newSensor);
    
    void startSensor(uint8_t id);
};

#endif  // SENSOR_MANAGER_H_
