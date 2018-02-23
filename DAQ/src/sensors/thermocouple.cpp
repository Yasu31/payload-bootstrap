#include "Arduino.h"
#include "thermocouple.h"

#line __LINE__ "thermocouple.cpp"

thermocouple::thermocouple(uint8_t clk, uint8_t cs, uint8_t data, double rate): sensor(), _amp(Adafruit_MAX31855(clk, cs, data)) {
    _value = 0;
    _interval = 200;
    
    _lastReading = 0;
    _startTime = 0;
    _startupTime = 1000;
    
    _avgCount = 0;
    _rate = rate;
}

void thermocouple::init() {
    sensor::init();
    _amp.begin();
}

void thermocouple::update() {
    if (_state == SENSOR_STARTUP) {
        if (millis() - _startTime > _startupTime) {
            _state = SENSOR_SLEEP;
        }
    }
    if (_state == SENSOR_READY) {
        if (millis() - _lastReading > _interval) {
            _value = _amp.readCelsius() / _rate;
            _lastReading = millis();
            _hasValue = true;
        }
    }
}
