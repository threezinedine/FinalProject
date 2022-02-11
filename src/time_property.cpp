#include <iostream>
#include <string>
#include <my_time.h>
#include <log_file.h>
#include <time_property.h>
#include <string_operators.h>
#include <error_message.h>
#include <data.h>


void TimeProperty :: setValueLong(long valueLong) {
    empty = false;
    this->valueLong = valueLong;
    this->time = new MyTime(valueLong);
    updateValue();
    updateHexValue();
}

TimeProperty :: TimeProperty(LogFile* logFile) {
    this->logFile = logFile;
}

TimeProperty :: TimeProperty(long valueLong, LogFile* logFile) {
    this->logFile = logFile;
}

void TimeProperty :: updateValue() {
    value = this->time->getFullTimeString();
}

void TimeProperty :: updateHexValue() {
    string hexStr = longToHexString(time->getUnixLongNumber());

    int i;
    for (i=0; i<4; i++) {
        hexValue += hexStr[2*i];
        hexValue += hexStr[2*i+1];
        if (i < 3) {
            hexValue += " ";
        }
    }
}

int TimeProperty :: getNumByte() {
    return numByte;
}

long TimeProperty :: getValueLong() {
    return valueLong;
}

string TimeProperty :: getValue() {
    return value;
}

string TimeProperty :: getHexValue() {
    return hexValue;
}

string TimeProperty :: getPropertyName() {
    return propertyName;
}

LogFile* TimeProperty :: getLogFile() {
    return logFile;
}

void TimeProperty :: setValue(string newValue) {
    if (newValue == "") {
        empty = true;
        logFile->addMessage(new ErrorMessage("16",
                            "Loss Time in row " + to_string(Data::NumRow)));
        return;
    }
    MyTime* temp = new MyTime(newValue);
    setValueLong(temp->getUnixLongNumber());
}

void TimeProperty :: setHexValue(string hexValueStr) {
    vector<string> hexVectorString = divideString(hexValueStr, ' ');
    setValueLong(hexStringToLong(hexVectorString));
}

bool TimeProperty :: isEmpty() {
    return empty;
}

int TimeProperty :: getSumStoreByte() {
    vector<string> hexVectorString = divideString(hexValue, ' ');
    int result = 0;

    for (string s: hexVectorString) {
        result += hexStringToInt(s);
    }
    return result;
}

int TimeProperty :: compareTo(IProperty* obj){
    if (empty) {
        if (obj->isEmpty()){
            return 0;
        }
        else{
            return -1;
        }
    }

    MyTime* temp = new MyTime(obj->getValue());
    long data = temp->getUnixLongNumber();
    if (valueLong > data) {
        return 1;
    }
    else if (valueLong == data){
        return 0;
    }
    else{
        return -1;
    }
}
