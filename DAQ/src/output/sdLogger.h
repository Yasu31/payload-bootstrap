#ifndef OUTPUT_SDLOGGER_H_
    #define OUTPUT_SDLOGGER_H_

#include <SD.h>
#include "../output.h"

class sdLogger : public output {
 private:
    SDTHING _sd;
    
 public:
    sdLogger(outputManager* om, uint8_t chipSelect);
    void init();
    void update();
};

#endif  // OUTPUT_SDLOGGER_H_