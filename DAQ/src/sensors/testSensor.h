#ifndef TESTSENSOR_H_
    #define TESTSENSOR_H_

#include "../sensor.h"

class testSensor : public sensor {
 private:
    uint32_t _lastReading;
 public:
    testSensor(uint32_t interval);
    void init();
    void update();
};

#endif  // TESTSENSOR_H_