#include <i2c_t3.h>// for some reason including wire in the library doesn't work, so do it here

#include <SD.h>
#include "Arduino.h"

#define DEBUG

#include "src/sensorManager.h"
#include "src/sensors/testSensor.h"

#include "src/outputManager.h"
#include "src/output/serialLogger.h"
#include "src/output/sdLogger.h"

sensorManager sm = sensorManager(1000);
outputManager om = outputManager();
testSensor* ts;
testSensor* ts2;
serialLogger* sl;
sdLogger* sdl;

void setup() {
    pinMode(13, OUTPUT);
    Serial.begin(9600);
    ts = new testSensor(1000, 100);
    ts2 = new testSensor(2000, 200);
    sm.registerSensor(ts);
    sm.registerSensor(ts2);
    sm.init();
    sl = new serialLogger(&om, 0, 9600);
    sdl = new sdLogger(&om, 10);
    om.registerOutput(sl);
    om.registerOutput(sdl);
    om.init();
}

void loop() {
    sm.update();
    om.update();
    delay(10);
    if(sm.getValuesReady()) {
        uint8_t num = sm.getNumSensors();
        memcpy(&om.values, &sm.values, sizeof(double) * num);
        om.dumpValues(num);
    }
}
