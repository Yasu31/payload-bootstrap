#include "Arduino.h"
#include "sdLogger.h"

#line __LINE__ "sdLogger.cpp"

sdLogger::sdLogger(outputManager* om, uint8_t chipSelect) :
    output(om) {
    _chipSelect = chipSelect;
}

void sdLogger::init() {
    output::init();
    
    if (!SD.begin(_chipSelect)) {
        _state = OUTPUT_ERROR;
        return;
    }
    
    if (SD.exists("last.txt")) {
        File logNumberFile = SD.open("last.txt", FILE_READ);
        uint16_t num = logNumberFile.parseInt();
        logNumberFile.close();

        num += 1;
        SD.remove("last.txt");
        logNumberFile = SD.open("last.txt", FILE_WRITE); 
        logNumberFile.println(num, DEC);
        logNumberFile.close();

        _fileName = String(num,DEC)+".txt";
    }
    else {
        _fileName = "0.txt";
        File logNumberFile = SD.open("last.txt", FILE_WRITE);
        logNumberFile.write("0");
        logNumberFile.close();
    }
    _state = OUTPUT_READY;
}

void sdLogger::update() {
}

void sdLogger::dumpValues(uint32_t time, uint8_t numValues) {
    _buffer = String(time, DEC) + ": ";
    for (uint8_t i = 0; i < numValues; i++) {
        _buffer += String(_om->values[i]); 
        if (i < numValues - 1) _buffer += ", ";
    }
    _buffer += "\n";
    _dataFile = SD.open(_fileName.c_str(), FILE_WRITE);
    _dataFile.print(_buffer);
    _dataFile.close();
}