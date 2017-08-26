#include "Arduino.h"
#include "testSensor.h"

#line __LINE__ "testSensor.cpp"

testSensor::testSensor(uint32_t interval) :
    sensor() {
    _interval = interval;
    _lastReading = 0;
    _value = 0;
}

void testSensor::init() {
    DEBUGMESS("Sensor started");
}

void testSensor::update() {
    if (millis() - _lastReading > _interval) {
        _value = _lastReading;
        _lastReading = millis();
        _hasValue = true;
    }
}
