#include <iostream>
#include <humidity_property.h>
#include <string_operators.h>
#include <i_message.h>
#include <error_message.h>
#include <sstream>
#include <log_file.h>


int HumidityProperty :: getNumByte() {
    return numByte;
}

string HumidityProperty :: getValue() {
    return value;
}

string HumidityProperty :: getHexValue() {
    return hexValue;
}

string HumidityProperty :: getPropertyName() {
    return propertyName;
}

LogFile* HumidityProperty :: getLogFile() {
    return logFile;
}

void HumidityProperty :: setValueInt(int newValueInt) {
    // if humidity not in range (40, 95) -> raise Error
    if (newValueInt < 40 || newValueInt > 95) {
        IMessage *msg = new ErrorMessage("04", "Humidity Property must be in range (40, 95).");
        logFile->addMessage(msg);
    }
    else {
        valueInt = newValueInt;
    }
    empty = false;
    updateValue();
    updateHexValue();
}

void HumidityProperty :: setValue(string newValue) {
    if (newValue == "") {
        empty = true;
        return;
    }
    empty = false;
    value = newValue;
    setValueInt(stringToInt(newValue));
}

void HumidityProperty :: setHexValue(string newHexValue) {
    empty = false;
    hexValue = newHexValue;

    //convert string newHexValue to int
    unsigned int temp; 
    stringstream conv;
    conv << hex << newHexValue;
    conv >> temp;
    setValueInt((int)temp);
}

HumidityProperty :: HumidityProperty (LogFile *logFile) {
    this->logFile = logFile;
}

HumidityProperty :: HumidityProperty (int valueInt, LogFile *logFile) {
    this->logFile = logFile;
    setValueInt(valueInt);
}

void HumidityProperty :: updateValue() {
    string valueStr = to_string(valueInt);
    value = getStringWithZero(valueStr, 2);
}

void HumidityProperty :: updateHexValue() {
    // get hex string of char array.
    char hex[numByte];
    sprintf(hex, "%X", valueInt);

    string hexStr = string(hex);
    hexValue = getStringWithZero(hexStr, 2);
}

bool HumidityProperty :: isEmpty() {
    return empty;
}

int HumidityProperty :: getSumStoreByte() {
    return valueInt;
}

int HumidityProperty :: compareTo(IProperty* obj) {
    int value = stringToInt(obj->getValue());
    if (this->valueInt > value) {
        return 1;
    }
    else if (this->valueInt == value){
        return 0;
    }
    else {
        return -1;
    }
}