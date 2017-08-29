#include "Arduino.h"
#include "serialLogger.h"

#line __LINE__ "serialLogger.cpp"

serialLogger::serialLogger(outputManager* om, uint8_t port, uint16_t baudRate) :
    output(om) {
    _port = port;
    _baudRate = baudRate;
}

void serialLogger::init() {
    output::init();
    switch(_port) {
        case 0:
            break;
        case 1:
            _serial = &Serial1;
            break;
        case 2:
            _serial = &Serial2;
            break;
        case 3:
            _serial = &Serial3;
            break;
    }
    if (_port != 0) _serial->begin(_baudRate);
    _state = OUTPUT_READY;
}

void serialLogger::update() {

}

void serialLogger::dumpValues(uint8_t numValues) {
    if (_port == 0) {
        for (uint8_t i = 0; i < numValues; i++) {
            Serial.print(_om->values[i]); 
            if (i < numValues - 1) Serial.print(", ");
        }
        Serial.println("");
    }
    else {
        for (uint8_t i = 0; i < numValues; i++) {
            _serial->print(_om->values[i]); 
            if (i < numValues - 1) _serial->print(", ");
        }
        _serial->println("");
    }
}