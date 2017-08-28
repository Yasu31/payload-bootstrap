#ifndef OUTPUT_H_
    #define OUTPUT_H_

#include "debug.h"
#include "outputManager.h"

enum outputState {OUTPUT_OFF, OUTPUT_STARTUP, OUTPUT_READY, OUTPUT_ERROR, OUTPUT_SLEEP};

class outputManager;

class output {
 protected:
    uint8_t _id;
    outputState _state;
    outputManager* _om;

 public:    
    explicit output(outputManager* om);
    virtual void init();  // Moves the output device from OFF to STARTUP, and begins communication with any hardware
    virtual void update() = 0;
    virtual void dumpValues(uint8_t numValues) = 0;
    outputState getState();
    
    void start();
    
};

#endif  // OUTPUT_H_
