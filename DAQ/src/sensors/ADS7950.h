#ifndef SENSORS_ADS7950_H_
    #define SENSORS_ADS7950_H_

#include "../sensor.h"
#include <SPI.h>

class ads7950 : public sensor {
 private:
    uint32_t _lastReading;
    uint32_t _startTime;
    uint32_t _startupTime;
    
    double _zeroVal;
    uint16_t _avgCount;
    double _rate;

    uint16_t spi_data;
    
 public:
    ads7950();
    void init();
    void update();
};

#endif  // SENSORS_ADS7950_H_
