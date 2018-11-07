#include "Arduino.h"
#include "sensor.h"

#line __LINE__ "sensor.cpp"

sensor::sensor(){
    _state = SENSOR_OFF;
}

void sensor::init(uint8_t channels){
  _channels = channels;
  _values = malloc(_channels*sizeof(double));
  for(int i=0; i<_channels; i++){
    ((double*)_values)[i] = 0.0;
  }
    _state = SENSOR_STARTUP;
}
void sensor::init(){

}

sensorState sensor::getState() {
    return _state;
}

bool sensor::getValueReady() {
    return _hasValue;
}

double sensor::getValue(uint8_t channel) {
  if (0<=channel && channel<_channels){
    _hasValue = false;
    return ((double*)_values)[channel];
  }
  return (double)-1.0;
}

void sensor::start() {
    if (_state == SENSOR_SLEEP) _state = SENSOR_READY;
}
