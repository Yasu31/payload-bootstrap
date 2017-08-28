#include "Arduino.h"
#include "sensor.h"

#line __LINE__ "sensor.cpp"

sensor::sensor() {
    _state = SENSOR_OFF;
}

void sensor::init() {
    _state = SENSOR_STARTUP;
}

void sensor::start() {
    _state = SENSOR_READY;
}

sensorState sensor::getState() {
    return _state;
}

bool sensor::getValueReady() {
    return _hasValue;
}

double sensor::getValue() {
    _hasValue = false;
    return _value;
}