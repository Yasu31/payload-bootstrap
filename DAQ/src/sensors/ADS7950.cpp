#include "Arduino.h"
#include "ADS7950.h"

#line __LINE__ "ADS7950.cpp"

ads7950::ads7950(){
  _interval = 1;

  _lastReading = 0;
  _startTime = 0;
  _startupTime = 100;

  _zeroVal = 0;
  _avgCount = 0;
  _rate = 0; //??
}

void ads7950::init(){
  //set up
  sensor::init(2);
  SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE0));
}

void ads7950::update(){
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
          spi_data = (B00000000 * 256) + B00000000; // set up correctly
          spi_data = SPI.transfer16(spi_data);
          // parse spi_data to extract acceleration data
          _hasValue = true;
        }
    }

  //parse data
}
