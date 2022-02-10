#include <iostream>
#include <temperature_property.h>
#include <string>
#include <log_file.h>
#include <i_message.h>
#include <error_message.h>
#include <sstream>
#include <string_operators.h>


TemperatureProperty :: TemperatureProperty(LogFile* logFile) {
    this->logFile = logFile;
}

TemperatureProperty :: TemperatureProperty(float valueFloat, LogFile* logFile) {
    this->logFile = logFile;
    setValueFloat(valueFloat);
}

void TemperatureProperty :: setValueFloat (float valueFloat) {
    if (valueFloat < -10 || valueFloat > 51) {
        IMessage* msg = new ErrorMessage("09", "Temperature must be in range.");
        logFile->addMessage(msg);
        return;
    }
    this->valueFloat = valueFloat;
    updateValue();
    updateHexValue();
}

void TemperatureProperty :: updateValue() {
    value = to_string(valueFloat);
}

void TemperatureProperty :: updateHexValue() {
    string hexStr = floatToHexString(valueFloat);

    int i;
    for (i=0; i<4; i++) {
        hexValue += hexStr[2*i];
        hexValue += hexStr[2*i+1];
        if (i<3) {
            hexValue += " ";
        }
    }
}

int TemperatureProperty :: getNumByte() {
    return numByte;
}

string TemperatureProperty :: getValue() {
    return value;
}

string TemperatureProperty :: getHexValue() {
    return hexValue;
}

string TemperatureProperty :: getPropertyName() {
    return propertyName;
}

LogFile* TemperatureProperty :: getLogFile() {
    return logFile;
}

void TemperatureProperty :: setValue(string value) {
    setValueFloat(stringToFloat(value));
}

bool TemperatureProperty :: isEmpty() {
    return empty;
}

void TemperatureProperty :: setHexValue(string hexValue) {
    vector<string> hexStringVector = divideString(hexValue, ' ');
    setValueFloat(hexStringToFloat(hexStringVector));
}

int TemperatureProperty :: getSumStoreByte() {
    vector<string> hexStringVector = divideString(hexValue, ' ');
    int result = 0;

    for (string s:hexStringVector) {
        result += hexStringToInt(s);
    }
    return result;
}

int TemperatureProperty :: compareTo(IProperty* obj) {
    float objValue = stringToFloat(obj->getValue());
    if (this->valueFloat > objValue){
        return 1;
    }
    else if (this->valueFloat == objValue) {
        return 0;
    }
    else {
        return -1;
    }
}