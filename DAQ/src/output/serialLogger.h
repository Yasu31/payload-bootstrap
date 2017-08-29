#ifndef OUTPUT_SERIALLOGGER_H_
    #define OUTPUT_SERIALLOGGER_H_

#include "../output.h"

class serialLogger : public output {
 private:
    uint8_t _port;
    uint16_t _baudRate;
    HardwareSerial* _serial;
    
 public:
    explicit serialLogger(outputManager* om, uint8_t port, uint16_t baudRate);
    void init();
    void update();
    void dumpValues(uint32_t time, uint8_t numValues);
};

#endif  // OUTPUT_SERIALLOGGER_H_