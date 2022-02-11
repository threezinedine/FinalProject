#pragma once
#include <iostream>
#include <string>
#include "one_byte_int_property.h"


/**
 * Class stores Humidity Property
 */
class HumidityProperty : public OneByteIntProperty {
    protected:
        string propertyName = "Humidity";
        void setValueInt(int newValueInt);

    public:
        HumidityProperty(LogFile* logFile);
        HumidityProperty(int valueInt, LogFile* logFile);

        string getPropertyName();
};