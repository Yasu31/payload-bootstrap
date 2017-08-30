#include "Arduino.h"
#include "daq.h"

#line __LINE__ "daq.cpp"

daq::daq() : _sm(sensorManager(1000)), _om(outputManager()) {
    _started = false;
}

void daq::init() {
    _ts = new testSensor(1000, 100);
    _ts2 = new testSensor(2000, 200);
    _pt = new pTap();
    _sm.registerSensor(_ts);
    _sm.registerSensor(_ts2);
    _sm.registerSensor(_pt);
    
    _sm.init();
    
    _sl = new serialLogger(&_om, 0, 9600);
    _sdl = new sdLogger(&_om, 10);
    _om.registerOutput(_sl);
    _om.registerOutput(_sdl);
    
    _om.init();
}

void daq::update() {
    _sm.update();
    _om.update();
    if (_started) {
        delay(10);
        if(_sm.getValuesReady()) {
            uint8_t num = _sm.getNumSensors();
            memcpy(&_om.values, &_sm.values, sizeof(double) * num);
            _om.dumpValues(millis() - _startTime, num);
        }
    }
}

void daq::start() {
    if (!_started) {
        _om.start();
        _sm.start();
        _startTime = millis();
        _started = true;
    }
}

void daq::stop() {

}