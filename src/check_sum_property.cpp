#include <iostream>
#include <check_sum_property.h>
#include <log_file.h>
#include <string_operators.h>
#include <math.h>


int CheckSumProperty :: getNumByte() {
    return numByte;
}

string CheckSumProperty :: getValue() {
    return value;
}

string CheckSumProperty :: getHexValue() {
    return hexValue;
}

string CheckSumProperty :: getPropertyName() {
    return propertyName;
}

LogFile* CheckSumProperty :: getLogFile() {
    return logFile;
}

void CheckSumProperty :: setValueInt(int newValueInt) {
    valueInt = (int)pow(2, 8) - (newValueInt % (int)pow(2, 8));
    empty = false;
    updateValue();
    updateHexValue();
}

void CheckSumProperty :: setValue(string newValue) {
    if (newValue == "") {
        empty = true;
        return;
    }
    empty = false;
    setValueInt(stringToInt(newValue));
}

void CheckSumProperty :: setHexValue(string newHexValue) {
    empty = false;
    setValueInt(hexStringToInt(newHexValue));
}

CheckSumProperty :: CheckSumProperty (LogFile *logFile) {
    this->logFile = logFile;
}

CheckSumProperty :: CheckSumProperty (int valueInt, LogFile *logFile) {
    this->logFile = logFile;
    setValueInt(valueInt);
}

void CheckSumProperty :: updateValue() {
    string valueStr = to_string(valueInt);
    value = getStringWithZero(valueStr, 2);
}

void CheckSumProperty :: updateHexValue() {
    hexValue = intToHexString(valueInt);
}

bool CheckSumProperty :: isEmpty() {
    return empty;
}

int CheckSumProperty :: getSumStoreByte() {
    return 0;
}

int CheckSumProperty :: compareTo(IProperty* obj) {
    return 0;
}