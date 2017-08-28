#include "Arduino.h"
#include "output.h"

#line __LINE__ "output.cpp"

output::output(outputManager* om) {
    _om = om;
    _state = OUTPUT_OFF;
}

void output::init() {
    _state = OUTPUT_STARTUP;
}

void output::start() {
    _state = OUTPUT_READY;
}

outputState output::getState() {
    return _state;
}