#ifndef SENSORS_THERMOCOUPLE_H_
    #define SENSORS_THERMOCOUPLE_H_

#include "../sensor.h"

class thermocouple : public sensor {
 private:
    Adafruit_MAX31855 _amp;
    uint32_t _lastReading;
    uint32_t _startTime;
    uint32_t _startupTime;
    
    uint16_t _avgCount;
    double _rate;
    
 public:
    thermocouple(uint8_t clk, uint8_t cs, uint8_t data, double rate);
    void init();
    void update();
};

#endif  // SENSORS_THERMOCOUPLE_H_