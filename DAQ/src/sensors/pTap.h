#ifndef SENSORS_PTAP_H_
    #define SENSORS_PTAP_H_

#include "../sensor.h"

class Adafruit_ADS1115;

class pTap : public sensor {
 private:
    Adafruit_ADS1115 _amp;
    uint32_t _lastReading;
    uint32_t _startTime;
    uint32_t _startupTime;

    double _zeroVal;
    uint16_t _avgCount;
    double _rate;
    
 public:
    pTap(uint8_t address, double rate);
    void init();
    void update();
};

#endif  // SENSORS_PTAP_H_