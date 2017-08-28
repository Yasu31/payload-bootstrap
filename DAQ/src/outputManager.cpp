#include "Arduino.h"
#include "outputManager.h"

#line __LINE__ "outputManager.cpp"

outputManager::outputManager() {
    _numOutputs = 0;
}

void outputManager::init() {
    for (int i = 0; i < _numOutputs; i++) {
        _outputs[i]->init();
    }
}

void outputManager::update() {
}

uint8_t outputManager::registerOutput(output* newOutput) {
    if (_numOutputs < MAX_OUTPUTS - 1) {
        _outputs[_numOutputs] = newOutput;
        _numOutputs++;
        return _numOutputs;
    }
    return 33;
}

void outputManager::dumpValues(uint8_t numValues) {
    for (int i = 0; i < _numOutputs; i++) {
        _outputs[i]->dumpValues(numValues);
    }
}

void outputManager::startOutput(uint8_t id)
{
    if (id < MAX_OUTPUTS) _outputs[id]->start();
}
