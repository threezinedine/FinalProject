#include <iostream>
#include <string>
#include <sensor_id_property.h>
#include <error_message.h>
#include <i_message.h>
#include <log_file.h>
#include <string_operators.h>
#include <sstream>


int SensorIDProperty :: getNumByte() {
    return numByte;
}

string SensorIDProperty :: getValue() {
    return value;
}

string SensorIDProperty :: getHexValue() {
    return hexValue;
}

string SensorIDProperty :: getPropertyName() {
    return propertyName;
}

LogFile* SensorIDProperty :: getLogFile() {
    return logFile;
}

void SensorIDProperty :: setValueInt(int newValueInt) {
    // if sensor value <= 0 -> raise Error
    if (newValueInt <= 0) {
        IMessage *msg = new ErrorMessage("03", "Sensor ID cannot be less than zero.");
        logFile->addMessage(msg);
    }
    else {
        valueInt = newValueInt;
    }
    empty = false;
    updateValue();
    updateHexValue();
}

void SensorIDProperty :: setValue(string newValue) {
    if (newValue == "") {
        empty = true;
        return;
    }
    empty = false;
    value = newValue;
    setValueInt(stringToInt(newValue));
}

void SensorIDProperty :: setHexValue(string newHexValue) {
    empty = false;

    //convert string newHexValue to int
    unsigned int temp; 
    stringstream conv;
    conv << hex << newHexValue;
    conv >> temp;
    setValueInt((int)temp);
}

SensorIDProperty :: SensorIDProperty (LogFile *logFile) {
    this->logFile = logFile;
}

SensorIDProperty :: SensorIDProperty (int valueInt, LogFile *logFile) {
    this->logFile = logFile;
    setValueInt(valueInt);
}

void SensorIDProperty :: updateValue() {
    string valueStr = to_string(valueInt);
    value = getStringWithZero(valueStr, 2);
}

void SensorIDProperty :: updateHexValue() {
    // get hex string of char array.
    char hex[numByte];
    sprintf(hex, "%X", valueInt);

    string hexStr = string(hex);
    hexValue = getStringWithZero(hexStr, 2);
}

bool SensorIDProperty :: isEmpty() {
    return empty;
}

int SensorIDProperty :: getSumStoreByte() {
    return valueInt;
}
