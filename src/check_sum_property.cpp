#include <iostream>
#include <check_sum_property.h>
#include <log_file.h>
#include <string_operators.h>
#include <math.h>


void CheckSumProperty :: setValueInt(int newValueInt) {
    valueInt = (int)pow(2, 8) - (newValueInt % (int)pow(2, 8));
    empty = false;
    updateValue();
    updateHexValue();
}

CheckSumProperty :: CheckSumProperty (LogFile *logFile) {
    this->logFile = logFile;
}

CheckSumProperty :: CheckSumProperty (int valueInt, LogFile *logFile) {
    this->logFile = logFile;
    setValueInt(valueInt);
}

string CheckSumProperty :: getPropertyName() {
    return propertyName;
}