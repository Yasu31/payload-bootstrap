//
// Created by Yasunori Toshimitsu on 2018/11/08.
//

#include "Arduino.h"
#include "voltageRead.h"

#line __LINE__ "ADS7950.cpp"

voltageRead::voltageRead(){
    _interval = 1000;

    _lastReading = 0;
    _startTime = 0;
    _startupTime = 100;

    _zeroVal = 0;
    _avgCount = 0;
    _rate = 0; //??
}

void voltageRead::init(){
    //set up
    sensor::init(2);
}

void voltageRead::update(){
    if (_state == SENSOR_STARTUP) {
        if (millis() - _startTime > _startupTime) {
            _state = SENSOR_READY;
        }
        else {
            // wait for sensor to start up.
        }
    }
    if (_state == SENSOR_READY) {
        if (millis() - _lastReading > _interval) {
            _lastReading = millis();

            ((double *) _values)[0] = 20.0;
            ((double *) _values)[1] = 10.0;
            _hasValue = true;
        }
    }

    //parse data
}
