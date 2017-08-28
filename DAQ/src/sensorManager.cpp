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
    for (int i = 0; i < _numSensors; i++) {
        if (_sensors[i]->getValueReady()) {
            values[i] = _sensors[i]->getValue();
        }
    }
}

uint8_t sensorManager::registerSensor(sensor* newSensor) {
    if (_numSensors < MAX_SENSORS - 1) {
        _sensors[_numSensors] = newSensor;
        _numSensors++;
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
