#ifndef SENSORS_PTAP_H_
    #define SENSORS_PTAP_H_

#include "../sensor.h"
#include <Adafruit_ADS1015.h>

class pTap : public sensor {
 private:
    Adafruit_ADS1115 _amp;
    uint32_t _lastReading;
    uint32_t _startTime;
    uint32_t _startupTime;
    
 public:
    pTap();
    void init();
    void update();
};

#endif  // SENSORS_PTAP_H_