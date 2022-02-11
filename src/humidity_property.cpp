#include <iostream>
#include <humidity_property.h>
#include <string_operators.h>
#include <i_message.h>
#include <error_message.h>
#include <sstream>
#include <log_file.h>
#include <data.h>


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
        empty = true;
        IMessage *msg = new ErrorMessage("04", 
                    "Humidity Property is not in range (40, 95) in row " 
                        + to_string(Data::NumRow));
        logFile->addMessage(msg);
        return;
    }
    valueInt = newValueInt;
    empty = false;
    updateValue();
    updateHexValue();
}

void HumidityProperty :: setValue(string newValue) {
    if (newValue == "") {
        empty = true;
        return;
    }
    setValueInt(stringToInt(newValue));
}

void HumidityProperty :: setHexValue(string newHexValue) {
    if (newHexValue == ""){
        empty = true;
        return;
    }
    setValueInt(hexStringToInt(newHexValue));
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
    hexValue = intToHexString(valueInt);
}

bool HumidityProperty :: isEmpty() {
    return empty;
}

int HumidityProperty :: getSumStoreByte() {
    return valueInt;
}

int HumidityProperty :: compareTo(IProperty* obj) {
    if (empty) {
        if (obj->isEmpty()){
            return 0;
        }
        else{
            return -1;
        }
    }
    
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