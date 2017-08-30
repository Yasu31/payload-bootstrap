#include <i2c_t3.h>// for some reason including wire in the library doesn't work, so do it here

#include <SD.h>
#include "Arduino.h"

#include "src/daq.h"

daq DAQ = daq();

void setup() {
    DAQ.init();
}

void loop() {
    DAQ.update();
    if (Serial.available() > 0) {
        DAQ.start();
    }
}
