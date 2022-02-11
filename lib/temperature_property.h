#pragma once
#include <iostream>
#include <string>
#include "four_byte_property.h"


class TemperatureProperty : public FourByteProperty {
    private:
        float valueFloat;

    protected:
        string propertyName = "Temperature";

        void setValueFloat(float valueFloat);
        void updateHexValue();
        void updateValue();

    public:
        TemperatureProperty(LogFile* logFile);
        TemperatureProperty(float valueFloat, LogFile* logFile);

        string getPropertyName();

        void setValue(string valueStr);
        void setHexValue(string hexValueStr);

        int compareTo(IProperty* obj);
};