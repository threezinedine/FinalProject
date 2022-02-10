#include <iostream>
#include <length_property.h>
#include <string>
#include <i_message.h>
#include <error_message.h>
#include <log_file.h>
#include <string_operators.h>


int LengthProperty :: getNumByte() {
    return numByte;
}

string LengthProperty :: getValue() {
    return value;
}

string LengthProperty :: getHexValue() {
    return hexValue;
}

string LengthProperty :: getPropertyName() {
    return propertyName;
}

LogFile* LengthProperty :: getLogFile() {
    return logFile;
}

void LengthProperty :: setValueInt(int newValueInt) {
    valueInt = newValueInt;
    empty = false;
    updateValue();
    updateHexValue();
}

void LengthProperty :: setValue(string newValue) {
    if (newValue == "") {
        empty = true;
        return;
    }
    empty = false;
    setValueInt(stringToInt(newValue));
}

void LengthProperty :: setHexValue(string newHexValue) {
    empty = false;
    setValueInt(hexStringToInt(newHexValue));
}

LengthProperty :: LengthProperty (LogFile *logFile) {
    this->logFile = logFile;
}

LengthProperty :: LengthProperty (int valueInt, LogFile *logFile) {
    this->logFile = logFile;
    setValueInt(valueInt);
}

void LengthProperty :: updateValue() {
    string valueStr = to_string(valueInt);
    value = getStringWithZero(valueStr, 2);
}

void LengthProperty :: updateHexValue() {
    hexValue = intToHexString(valueInt);
}

bool LengthProperty :: isEmpty() {
    return empty;
}

int LengthProperty :: getSumStoreByte() {
    return valueInt;
}

int LengthProperty :: compareTo(IProperty* obj) {
    return 0;
}