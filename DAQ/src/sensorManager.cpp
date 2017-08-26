#include "Arduino.h"
#include "sensorManager.h"

#line __LINE__ "sensorManager.cpp"

sensorManager::sensorManager() {
    _numSensors = 0;
}

void sensorManager::init() {

}

void sensorManager::update()
{
    for (int i = 0; i < _numSensors; i++) {
        _sensors[i]->update();
    }
    for (int i = 0; i < _numSensors; i++) {
        if (_sensors[i]->getValueReady()) {
            _values[i] = _sensors[i]->getValue();
        }
    }
}

uint8_t sensorManager::registerSensor(sensor* newSensor) {
    if (_numSensors < MAX_SENSORS - 1) {
        _sensors[_numSensors] = newSensor;
        _numSensors++;
        return _numSensors;
    }
}

void sensorManager::startSensor(uint8_t id)
{
    if (id < MAX_SENSORS) _sensors[id]->start();
}
