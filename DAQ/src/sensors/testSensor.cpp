#include "Arduino.h"
#include "testSensor.h"

#line __LINE__ "testSensor.cpp"

testSensor::testSensor(uint32_t startupTime, uint32_t interval) :
    sensor() {
    _interval = interval;
    _lastReading = 0;
    _value = 0;
    _startTime = 0;
    _startupTime = startupTime;
}

void testSensor::init() {
    sensor::init();
    _startTime = millis();
}

void testSensor::update() {
    if (_state == SENSOR_STARTUP) {
        if (millis() - _startTime > _startupTime) {
            //Serial.println("Sensor done");
            _state = SENSOR_READY;
        }
        else {
            //Serial.print("Waiting for sensor "); Serial.println(_startupTime);
        }
    }
    if (_state == SENSOR_READY) {
        if (millis() - _lastReading > _interval) {
            _value = _lastReading;
            _lastReading = millis();
            _hasValue = true;
        }
    }
}
