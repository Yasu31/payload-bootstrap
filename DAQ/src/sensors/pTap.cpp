#include "Arduino.h"
#include "pTap.h"

#line __LINE__ "pTap.cpp"

pTap::pTap() : sensor(), _amp(Adafruit_ADS1115(0x48)) {
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
            _value = (double) _amp.readADC_SingleEnded(0);
            _lastReading = millis();
            _hasValue = true;
        }
    }
}
