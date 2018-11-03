#include "Arduino.h"
#include "pTap.h"

#line __LINE__ "pTap.cpp"

pTap::pTap(uint8_t address, double rate) : sensor(), _amp(Adafruit_ADS1115(address)) {
    _value = 0;
    _interval = 25;
    
    _lastReading = 0;
    _startTime = 0;
    _startupTime = 1000;
    
    _zeroVal = 0;
    _avgCount = 0;
    _rate = rate;
}

void pTap::init() {
    sensor::init();
    _amp.begin();
}

void pTap::update() {
    if (_state == SENSOR_STARTUP) {
        if (millis() - _startTime > _startupTime) {
            _zeroVal /= _avgCount;
            _state = SENSOR_SLEEP;
        }
        else {
            _avgCount++;
            _zeroVal += (double) _amp.readADC_SingleEnded(0);
        }
    }
    if (_state == SENSOR_READY) {
        if (millis() - _lastReading > _interval) {
            _value = ((double) _amp.readADC_SingleEnded(0) - _zeroVal) / _rate;
            _lastReading = millis();
            _hasValue = true;
        }
    }
}
