#ifndef daq_H_
    #define daq_H_

#include "sensorManager.h"
#include "sensors/testSensor.h"

#include "outputManager.h"
#include "output/serialLogger.h"
#include "output/sdLogger.h"

class daq {
 private:
    sensorManager _sm;
    outputManager _om;
    
    testSensor* _ts;
    testSensor* _ts2;
    serialLogger* _sl;
    sdLogger* _sdl;

 public:
    daq();
    void init();
    void update();

};

#endif  // daq_H_
