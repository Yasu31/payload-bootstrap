#include "Arduino.h"
#include "daq.h"

#line __LINE__ "daq.cpp"

daq::daq() : _sm(sensorManager(20)), _om(outputManager()) {
    _started = false;
}

void daq::init() {
    _lc = new loadCell(0x48, 0.04426);
    _pt = new loadCell(0x49, 11.54);
    _tc = new thermocouple(3, 4, 5, 1.0);
    _sm.registerSensor(_lc);
    _sm.registerSensor(_pt);
    _sm.registerSensor(_tc);
    
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