#include <iostream>
#include <temperature_property.h>
#include <string>
#include <log_file.h>
#include <i_message.h>
#include <error_message.h>
#include <sstream>
#include <string_operators.h>
#include <data.h>


TemperatureProperty :: TemperatureProperty(LogFile* logFile) {
    this->logFile = logFile;
}

TemperatureProperty :: TemperatureProperty(float valueFloat, LogFile* logFile) {
    this->logFile = logFile;
    setValueFloat(valueFloat);
}

void TemperatureProperty :: setValueFloat (float valueFloat) {
    if (valueFloat < -10 || valueFloat > 51) {
        empty = true;
        IMessage* msg = new ErrorMessage("09", 
                "Temperature is not in range -10, 51 in row " + to_string(Data::NumRow));
        logFile->addMessage(msg);
        return;
    }
    this->valueFloat = valueFloat;
    empty = false;
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

void TemperatureProperty :: setValue(string value) {
    if (value == "") {
        empty = true;
        return;
    }
    empty = false;
    setValueFloat(stringToFloat(value));
}

void TemperatureProperty :: setHexValue(string hexValue) {
    if (hexValue == "") {
        empty = true;
        return;
    }
    vector<string> hexStringVector = divideString(hexValue, ' ');
    setValueFloat(hexStringToFloat(hexStringVector));
}

int TemperatureProperty :: compareTo(IProperty* obj) {
    if (empty) {
        if (obj->isEmpty()){
            return 0;
        }
        else{
            return -1;
        }
    }
    // cout << endl << stringToFloat(obj->getValue());
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

string TemperatureProperty :: getPropertyName() {
    return propertyName;
}