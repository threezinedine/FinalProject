#include <iostream>
#include <vector>
#include <data_row.h>
#include <string_operators.h>
#include <i_property.h>
#include <sensor_id_property.h>
#include <length_property.h>
#include <check_sum_property.h>


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

    // erase 2 first data (startByte and lengthByte)
    data.erase(data.begin());
    data.erase(data.begin());

    for (IProperty *property : properties) {
        int i = 0;
        vector<string> temp;
        for (i=0; i<property->getNumByte(); i++) {
            temp.push_back(data.front());
            data.erase(data.begin());
        }
        string dataPart = joinString(temp, ' ');
        property->setHexValue(dataPart);
    }
    return;
}

DataRow :: DataRow(string inputStr, LogFile* logFile) {
    this->logFile = logFile;
    if (isCSVData(inputStr)){
        setPropertiesWithCSV(inputStr);
    }
    else {
        setPropertiesWithTXT(inputStr);
    }
    length = getLength();
    checkSum = getCheckSum();
}

bool DataRow :: isValidDataRow(string inputStr) {
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
        result += property->getHexValue();
        result += " ";
    }
    result += checkSum->getHexValue() + " ";
    result += "FF";
    return result;
}

IProperty* DataRow :: getLength() {
    int valLength = 8;

    string result = "";
    for (IProperty* property: properties) {
        if (!property->isEmpty()) {
            valLength += property->getNumByte() * 2;
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