#include "Arduino.h"
#include "pTap.h"

#line __LINE__ "pTap.cpp"

pTap::pTap(uint8_t address) : sensor(), _amp(Adafruit_ADS1115(address)) {
    _value = 0;
    _interval = 100;
    
    _lastReading = 0;
    _startTime = 0;
    _startupTime = 1000;
}

void pTap::init() {
    sensor::init();
    _amp.begin();
}

void pTap::update() {
    if (_state == SENSOR_STARTUP) {
        if (millis() - _startTime > _startupTime) {
            _state = SENSOR_SLEEP;
        }
    }
    if (_state == SENSOR_READY) {
        if (millis() - _lastReading > _interval) {
            _value = (double) _amp.readADC_Differential_0_1();
            _lastReading = millis();
            _hasValue = true;
        }
    }
}
