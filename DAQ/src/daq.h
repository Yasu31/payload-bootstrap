#ifndef daq_H_
#define daq_H_

#include "sensorManager.h"
#include "sensors/testSensor.h"
#include "sensors/ADS7950.h"

#include "outputManager.h"
#include "output/serialLogger.h"
#include "output/sdLogger.h"

class daq {
    // topmost class for the DAQ. Provides easy interface that the Arduino code can call.
private:
    sensorManager _sm; // sensorManager consolidates all sensors
    outputManager _om; // oututManager consolidates all output methods (serial and SD card)

    // declare sensors
    ads7950 *_ads7950; // class representing ADC (inherits from sensor class)

    // declare outputs
    serialLogger *_sl;
    sdLogger *_sdl;

    bool _started;
    uint32_t _startTime;

public:
    daq();

    void init(); //initiate code
    void update(); //call to get value from sensors and write to outputs

    void start();

    void stop();
};

#endif  // daq_H_
