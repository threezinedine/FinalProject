#include <iostream>
#include <string>
#include <sensor_id_property.h>
#include <error_message.h>
#include <i_message.h>
#include <log_file.h>
#include <string_operators.h>
#include <sstream>
#include <data.h>


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
        empty = true;
        IMessage *msg = new ErrorMessage("03", 
                    "Sensor ID is less than zero in row " + to_string(Data::NumRow));
        logFile->addMessage(msg);
        return;
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
        logFile->addMessage(new ErrorMessage("11", 
                    "Loss Sensor ID in row " + to_string(Data::NumRow)));
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
    else if (this->valueInt == value) {
        return 0;
    }
    else {
        return -1;
    }
}
