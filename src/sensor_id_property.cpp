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
    setValueInt(hexStringToInt(newHexValue));
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
    hexValue = intToHexString(valueInt);
}

bool SensorIDProperty :: isEmpty() {
    return empty;
}

int SensorIDProperty :: getSumStoreByte() {
    return valueInt;
}

int SensorIDProperty :: compareTo(IProperty* obj) {
    int value = stringToInt(obj->getValue());
    if (this->valueInt > value) {
        return 1;
    }
    else if (this->valueInt == value) {
        return 0;
    }
    else {
        return -1;
    }
}
