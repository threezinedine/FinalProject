#include <iostream>
#include <vector>
#include <data_row.h>
#include <string_operators.h>
#include <i_property.h>
#include <sensor_id_property.h>
#include <length_property.h>
#include <check_sum_property.h>
#include <time_property.h>
#include <error_message.h>
#include <data.h>
#include <warning_message.h>


bool DataRow :: isCSVData(string inputStr){
    if (inputStr[0] == '0' && inputStr[1] == '0') {
        return false;
    }
    else {
        return true;
    }
}

void DataRow :: setPropertiesWithCSV(string inputString) {
    vector<string> data = divideString(inputString, ',');
    
    for (IProperty* property : properties) {
        property->setValue(data.front());
        data.erase(data.begin());
    }
}

void DataRow :: setPropertiesWithTXT(string inputString) {
    vector<string> data = divideString(inputString, ' ');

    int mode;
    //check the number of received bits
    if (data.size() == 4 + 1 + 4 + 4 + 1){
        mode = 0;   // enough data
    }
    else if (data.size() == 4 + 1 + 4 + 1){
        mode = 1; // leak temp
    }
    else if (data.size() == 4 + 1 + 4 + 4){
        mode = 2; // leak humi
    }
    else{
        mode = 3; //invalid
    }

    // erase 2 first data (startByte and lengthByte)
    data.erase(data.begin());
    data.erase(data.begin());
    
    int index = 0;
    for (IProperty *property : properties) {
        int i = 0;
        if (mode==0 || (mode==1 && index!=2) || (mode==2 && index!=3)){
            vector<string> temp;
            for (i=0; i<property->getNumByte(); i++) {
                temp.push_back(data.front());
                data.erase(data.begin());
            }
            string dataPart = joinString(temp, ' ');
            property->setHexValue(dataPart);
        }
        else{
            property->setHexValue("");
        }
        index ++;
    }
    return;
}

DataRow :: DataRow(string inputStr, LogFile* logFile) {
    this->logFile = logFile;

    this->properties.push_back(new SensorIDProperty(this->logFile));
    this->properties.push_back(new TimeProperty(this->logFile));
    this->properties.push_back(new TemperatureProperty(this->logFile));
    this->properties.push_back(new HumidityProperty(this->logFile));
    numProperties = this->properties.size();

    if (isCSVData(inputStr)){
        setPropertiesWithCSV(inputStr);
    }
    else {
        setPropertiesWithTXT(inputStr);
    }
    length = getLength();
    checkSum = getCheckSum();
}

// bool DataRow :: isValidDataRowCSV() {
    
// }

// bool DataRow :: isValidDataRowTXT() {
//     return true;
// }

bool DataRow :: isValidDataRow() {
    if (getPropertyByIndex(0)->isEmpty()){
        return false;
    }
    if (getPropertyByIndex(1)->isEmpty()){
        return false;
    }
    if (getPropertyByIndex(2)->isEmpty()){
        if (getPropertyByIndex(3)->isEmpty()) {
            logFile->addMessage(new ErrorMessage("20", 
                    "Loss both Temperature and Humidity in row " + to_string(Data::NumRow)));
            return false;
        }
        else {
            logFile->addMessage(new WarningMessage("21", 
                    "Loss Temperature in row " + to_string(Data::NumRow)));
            return true;
        }
    }
    else if(getPropertyByIndex(3)->isEmpty()){
        logFile->addMessage(new WarningMessage("21", 
                    "Loss Humidity in row " + to_string(Data::NumRow)));
        return true;
    }
    if (getPropertyByIndex(3)->isEmpty()) {
        return true;
    }
    return true;
}

string DataRow :: getHeaderLine() {
    string result = "";
    
    int index = 0;
    for (IProperty* property: properties) {
        result += property->getPropertyName();
        if (index < numProperties - 1) {
            result += ",";
            index ++;
        }
    }
    return result;
}

string DataRow :: getSaveDataCSV() {
    string result = "";

    int index = 0;
    for (IProperty* property: properties) {
        result += property->getValue();
        if (index < numProperties - 1) {
            result += ",";
            index ++;
        }
    }
    return result;
}

string DataRow :: getSaveDataTXT() {
    string result = "00 ";
    result += length->getHexValue() + " ";

    for (IProperty* property: properties) {
        if (!property->isEmpty()) {
            result += property->getHexValue();
            result += " ";
        }
    }
    result += checkSum->getHexValue() + " ";
    result += "ff";
    return result;
}

IProperty* DataRow :: getLength() {
    int valLength = 4;

    string result = "";
    for (IProperty* property: properties) {
        if (!property->isEmpty()) {
            valLength += property->getNumByte();
        }
    }
    IProperty *newLength = new LengthProperty(valLength, logFile);
    return newLength;
}

IProperty* DataRow :: getCheckSum() {
    int sum = length->getSumStoreByte();
    for (IProperty* property: properties) {
        if (!property->isEmpty()) {
            sum += property->getSumStoreByte();
        }
    }
    IProperty *newSumCheck = new CheckSumProperty(sum, logFile);
    return newSumCheck;
}

IProperty* DataRow :: getPropertyByIndex(int index) {
    int i = 0;

    for (IProperty *property: properties){
        if (i == index) {
            return property;
        }
        i ++;
    }
}

int DataRow :: getNumProperties() {
    return numProperties;
}