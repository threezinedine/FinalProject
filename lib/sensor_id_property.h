#pragma once
#include <iostream>
#include "one_byte_int_property.h"


/**
 * Class stores SensorIDProperty.
 *      Class inherits OnByteIntPropety
 */
class SensorIDProperty : public OneByteIntProperty {
    protected:
        string propertyName = "Sensor ID";
        void setValueInt(int newValueInt);

    public:
        SensorIDProperty(LogFile* logFile);
        SensorIDProperty(int valueInt, LogFile* logFile);

        string getPropertyName();
};