#include <SD.h>
#include "Arduino.h"

#include "src/daq.h"

daq DAQ = daq();

void setup() {
    DAQ.init();
}

void loop() {
    DAQ.update();
    if (millis() > 5000) {
        DAQ.start();
    }
}
