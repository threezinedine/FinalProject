#include <iostream>
#include <length_property.h>
#include <string>
#include <i_message.h>
#include <error_message.h>
#include <log_file.h>
#include <string_operators.h>


void LengthProperty :: setValueInt(int newValueInt) {
    valueInt = newValueInt;
    empty = false;
    updateValue();
    updateHexValue();
    // cout << newValueInt << " " << value << " " << hexValue << endl;
}

LengthProperty :: LengthProperty (LogFile *logFile) {
    this->logFile = logFile;
}

LengthProperty :: LengthProperty (int valueInt, LogFile *logFile) {
    this->logFile = logFile;
    setValueInt(valueInt);
    // cout << endl << numByte;
}

string LengthProperty :: getPropertyName() {
    return propertyName;
}