#include <iostream>
#include <string>
#include <four_byte_property.h>
#include <string_operators.h>


int FourByteProperty :: getSumStoreByte() {
    /*
        Step 1: Divide string to 4 strings (by ' ')
        Step 2: For each string -> convert to int value
        Step 3: Sum up 4 value to get result.
    */
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