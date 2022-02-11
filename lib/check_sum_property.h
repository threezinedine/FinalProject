#pragma once
#include <iostream>
#include "one_byte_int_property.h"
#include <string>


class CheckSumProperty : public OneByteIntProperty {
    protected:
        string propertyName = "Check Sum";

        void setValueInt(int newValueInt);

    public:
        CheckSumProperty(LogFile* logFile);
        CheckSumProperty(int valueInt, LogFile* logFile);

        string getPropertyName();
};