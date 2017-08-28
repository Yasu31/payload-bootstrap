#ifndef SENSOR_MANAGER_H_
    #define SENSOR_MANAGER_H_
    
#include "sensor.h"

#define MAX_SENSORS 32

class sensorManager {
 private:
    sensor* _sensors[MAX_SENSORS];
    uint8_t _numSensors;
    uint32_t _interval;
    uint32_t _intervalStarted;

 public:
    sensorManager(uint32_t interval);
    void init();
    void update();
    
    uint8_t registerSensor(sensor* newSensor);
    uint8_t getNumSensors();
    
    bool getValuesReady();
    
    void startSensor(uint8_t id);
    double values[MAX_SENSORS];
};

#endif  // SENSOR_MANAGER_H_
