#ifndef SENSOR_H_
#define SENSOR_H_

#include "debug.h"
//#include <Adafruit_ADS1015.h>
//#include <Adafruit_MAX31855.h>

// Sensor lifecycle: Off: Construction. Startup: init until enough loops for the sensor to be ready. Ready: Sensor is sending values

enum sensorState {
    SENSOR_OFF, SENSOR_STARTUP, SENSOR_READY, SENSOR_ERROR, SENSOR_SLEEP
};

class sensor {
protected:
    uint8_t _id;
    sensorState _state;
    uint32_t _interval;
    void *_values;
    bool _hasValue; // used to indicate that the sensor has new data ready


public:
    sensor();

    virtual void init(uint8_t);  // Moves the sensor from OFF to STARTUP, and begins communication with any hardware. Set the number of channels that this sensor uses.
    virtual void init();

    virtual void update() = 0;

    sensorState getState();

    bool getValueReady();

    double getValue(uint8_t);

    void start();

    uint8_t _channels; // how many channels of data this sensor has.


};

#endif  // SENSOR_H_
