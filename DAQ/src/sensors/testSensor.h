#ifndef TESTSENSOR_H_
    #define TESTSENSOR_H_

#include "../sensor.h"

class testSensor : public sensor {
 private:
    uint32_t _lastReading;
    uint32_t _startTime;
    uint32_t _startupTime;
    
 public:
    testSensor(uint32_t startupTime, uint32_t interval);
    void init();
    void update();
};

#endif  // TESTSENSOR_H_