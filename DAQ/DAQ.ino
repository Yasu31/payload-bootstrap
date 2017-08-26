#include <i2c_t3.h>// for some reason including wire in the library doesn't work, so do it here

#include <SD.h>
#include "Arduino.h"

#define DEBUG

#include "src/sensorManager.h"
#include "src/sensors/testSensor.h"
#include "src/debug.h"

sensorManager sm = sensorManager();
testSensor* ts;
testSensor* ts2;

void setup() {
    pinMode(13, OUTPUT);
    Serial.begin(9600);
    ts = new testSensor(100);
    ts2 = new testSensor(200);
    sm.registerSensor(ts);
    sm.registerSensor(ts2);
}

void loop() {
    sm.update();
}
