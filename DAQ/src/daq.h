#ifndef daq_H_
    #define daq_H_

#include "sensorManager.h"
#include "sensors/testSensor.h"
#include "sensors/pTap.h"
#include "sensors/loadCell.h"
#include "sensors/thermocouple.h"

#include "outputManager.h"
#include "output/serialLogger.h"
#include "output/sdLogger.h"

class daq {
 private:
    sensorManager _sm;
    outputManager _om;
    
    loadCell* _pt;
    loadCell* _lc;
    thermocouple* _tc;
    serialLogger* _sl;
    sdLogger* _sdl;
    
    bool _started;
    uint32_t _startTime;

 public:
    daq();
    void init();
    void update();
    
    void start();
    void stop();
};

#endif  // daq_H_
