#include <iostream>
#include <string>
#include <four_byte_property.h>
#include <string_operators.h>


int FourByteProperty :: getSumStoreByte() {
    vector<string> hexVectorString = divideString(hexValue, ' ');
    int result = 0;

    for (string s: hexVectorString) {
        result += hexStringToInt(s);
    }
    return result;
}

int FourByteProperty :: getNumByte() {
    return numByte;
}