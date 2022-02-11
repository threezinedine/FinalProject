#pragma once
#include <iostream>
#include "one_byte_int_property.h"
#include <string>
#include <log_file.h>


class LengthProperty : public OneByteIntProperty {
    protected:
        string propertyName = "Length";

        void setValueInt(int newValueInt);
    public:
        LengthProperty(LogFile* logFile);
        LengthProperty(int valueInt, LogFile* logFile);

        string getPropertyName();
};