#include <iostream>
#include <one_byte_int_property.h>
#include <i_property.h>
#include <data.h>
#include <string_operators.h>
#include <error_message.h>


void OneByteIntProperty :: updateValue(){
    string valueStr = to_string(valueInt);
    value = getStringWithZero(valueStr, 2);
}

void OneByteIntProperty :: updateHexValue(){
    hexValue = intToHexString(valueInt);
}

void OneByteIntProperty :: setValue(string value){
    if (value == "") {
        logFile->addMessage(new ErrorMessage("11", 
                    "Loss " + getPropertyName() + " in row " + to_string(Data::NumRow)));
        empty = true;
        return;
    }
    empty = false;
    setValueInt(stringToInt(value));
}

void OneByteIntProperty :: setHexValue(string hexValue) {
    if (hexValue == "") {
        empty = true;
        return;
    }
    empty = false;
    setValueInt(hexStringToInt(hexValue));
}

int OneByteIntProperty :: getSumStoreByte() {
    return valueInt;
}

int OneByteIntProperty :: compareTo(IProperty* obj) {
    // compare if object value is empty
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

int OneByteIntProperty :: getNumByte() {
    return numByte;
}