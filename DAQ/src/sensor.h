#ifndef SENSOR_H_
    #define SENSOR_H_

#include "debug.h"

enum sensorState {OFF, STARTUP, READY, ERROR, SLEEP};

class sensor {
 protected:
    uint8_t _id;
    sensorState _state;
    uint32_t _interval;
    double _value;
    bool _hasValue;

 public:
    sensor();
    virtual void init();  // Moves the sensor from OFF to STARTUP, and begins communication with any hardware
    virtual void update() = 0;
    sensorState getState();
    bool getValueReady();
    double getValue();
    
    void start();
};

#endif  // SENSOR_H_
