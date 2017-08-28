#ifndef OUTPUT_SDLOGGER_H_
    #define OUTPUT_SDLOGGER_H_

#include <SD.h>
#include "../output.h"

class sdLogger : public output {
 private:
    String _fileName;
    uint8_t _chipSelect;
    File _dataFile;
    String _buffer;

 public:
    sdLogger(outputManager* om, uint8_t chipSelect);
    void init();
    void update();
    void dumpValues(uint8_t numValues);
};

#endif  // OUTPUT_SDLOGGER_H_