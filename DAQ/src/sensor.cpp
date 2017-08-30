#include "Arduino.h"
#include "sensor.h"

#line __LINE__ "sensor.cpp"

sensor::sensor() {
    _state = SENSOR_OFF;
}

void sensor::init() {
    _state = SENSOR_STARTUP;
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

void sensor::start() {
    if (_state == SENSOR_SLEEP) _state = SENSOR_READY;
}