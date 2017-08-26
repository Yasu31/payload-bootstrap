#ifndef DEBUG_H_
    #define DEBUG_H_

#include "Arduino.h"

#ifdef DEBUG
    #define DEBUGMARK DEBUGMESS();
    #define DEBUGMESS(x) Serial.print(micros()); Serial.print(":"); Serial.print(__FILE__); Serial.print(":"); Serial.print(__LINE__+1); Serial.print(":"); Serial.println(x)
#else
    #define DEBUGMARK
    #define DEBUGMESS
#endif  // DEBUG

#endif  // DEBUG_H_
