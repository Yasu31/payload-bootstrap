
//
// Created by Yasunori Toshimitsu on 2018/11/08.
//

#ifndef DAQ_VOLTAGEREAD_H
#define DAQ_VOLTAGEREAD_H

#include "../sensor.h"

class voltageRead : public sensor {
private:
    uint32_t _lastReading;
    uint32_t _startTime;
    uint32_t _startupTime;

    double _zeroVal;
    uint16_t _avgCount;
    double _rate;

public:
    voltageRead();
    void init();
    void update();
};


#endif //DAQ_VOLTAGEREAD_H
