#include "Arduino.h"
#include "loadCell.h"

#line __LINE__ "loadCell.cpp"

loadCell::loadCell(uint8_t address, double rate) : sensor(), _amp(Adafruit_ADS1115(address)) {
    _value = 0;
    _interval = 25;
    
    _lastReading = 0;
    _startTime = 0;
    _startupTime = 1000;
    
    _zeroVal = 0;
    _avgCount = 0;
    _rate = rate;
}

void loadCell::init() {
    sensor::init();
    _amp.begin();
    _amp.setGain(GAIN_SIXTEEN);
}

void loadCell::update() {
    if (_state == SENSOR_STARTUP) {
        if (millis() - _startTime > _startupTime) {
            _zeroVal /= _avgCount;
            _state = SENSOR_SLEEP;
        }
        else {
            _avgCount++;
            _zeroVal += (double) _amp.readADC_Differential_0_1();
        }
    }
    if (_state == SENSOR_READY) {
        if (millis() - _lastReading > _interval) {
            _value = ((double) _amp.readADC_Differential_0_1() - _zeroVal) / _rate;
            _lastReading = millis();
            _hasValue = true;
        }
    }
}
