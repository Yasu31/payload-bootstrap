#ifndef OUTPUT_MANAGER_H_
    #define OUTPUT_MANAGER_H_
    
#include "output.h"

#define MAX_OUTPUTS 32

class output;

class outputManager {
 private:
    output* _outputs[MAX_OUTPUTS];
    uint8_t _numOutputs;

 public:
    outputManager();
    void init();
    void update();
    
    double values[MAX_OUTPUTS];

    
    uint8_t registerOutput(output* newOutput);
    
    void dumpValues(uint32_t time, uint8_t numValues);
    
    void startOutput(uint8_t id);
};

#endif  // OUTPUT_MANAGER_H_
