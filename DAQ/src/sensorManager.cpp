#include "Arduino.h"
#include "sensorManager.h"

#line __LINE__ "sensorManager.cpp"

sensorManager::sensorManager(uint32_t interval) {
    _numSensors = 0;
    _interval = interval;
}

void sensorManager::init() {
    for (int i = 0; i < _numSensors; i++) {
        _sensors[i]->init();
    }
    _intervalStarted = millis();
}

void sensorManager::update()
{
    for (int i = 0; i < _numSensors; i++) {
        _sensors[i]->update();
    }
    int j=0;
    for (int i = 0; i < _numSensors; i++) {
        if (_sensors[i]->getValueReady()) {
          for(int k=0; k< _sensors[i]->_channels; k++){
            //todo: record TIME (nanoseconds?) of measurement as well
            values[j] = _sensors[i]->getValue(k);
            j++;
          }
        }
    }
}

void sensorManager::start() {
    for (int i = 0; i < _numSensors; i++) {
        startSensor(i);
    }
}

uint8_t sensorManager::registerSensor(sensor* newSensor) {
  if (_numSensors < (MAX_SENSORS - newSensor->_channels)) {
        _sensors[_numSensors] = newSensor;
        _numSensors+=newSensor->_channels;
        return _numSensors;
    }
    return 33;
}

uint8_t sensorManager::getNumSensors() {
    return _numSensors;
}

bool sensorManager::getValuesReady() {
    if (millis() - _intervalStarted >= _interval) {
        _intervalStarted = millis();
        return true;
    }
    return false;
}

void sensorManager::startSensor(uint8_t id)
{
    if (id < MAX_SENSORS) _sensors[id]->start();
}
